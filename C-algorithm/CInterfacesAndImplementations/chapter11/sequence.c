#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "assert.h"
#include "sequence.h"
#include "array.h"
#include "arrayrep.h"
#include "mem.h"

#define T Sequence_T

struct T{
	struct Array_T array;
	int length;
	int head;
};

// static functions


// functions
T Sequence_new(int hint){
	T seq;
	
	assert(hint >= 0);
	
	NEW0(seq);
	if (hint == 0){
		hint = 16;
	}
	ArrayRep_init(&seq->array, hint, sizeof(void *), ALLOC(hint * sizeof(void *)));
	
	return seq;
}


T Sequence_seq(void *x, ...){
	va_list ap;
	T seq = Sequence_new(0);
	
	va_start(ap, x);
	for (; x; x = va_arg(ap, void *)){
		Sequence_addhi(seq, x);
	}
	va_end(ap);
	
	return seq;
}


void Sequence_free(T *seq){
	assert(seq && *seq);
	assert((void *)*seq == (void *)&(*seq)->array);
	
	Array_free((Array_T *)seq);
}


int Sequence_length(T seq){
	assert(seq);
	
	return seq->length;
}


void *Sequence_get(T seq, int i){
	assert(seq);
	assert(i >= 0 && i < seq->length);
	
	return ((void **)seq->array.array)[(seq->head + i) % seq->array.length];
}


void *Sequence_put(T seq, int i, void *x){
	void *prev;
	
	assert(seq);
	assert(i >= 0 && i < seq->length);
	
	prev = ((void **)seq->array.array)[(seq->head + i) % seq->array.length];
	((void **)seq->array.array)[(seq->head + i) % seq->array.length] = x;
	
	return prev;
}


void *Sequence_removehi(T seq){
	int i;
	
	assert(seq);
	assert(seq->length > 0);
	
	i = --seq->length;
	
	return ((void **)seq->array.array)[(seq->head + i) % seq->array.length];
}


void *Sequence_removelo(T seq){
	int i = 0;
	void *x;
	
	assert(seq);
	assert(seq->length > 0);
	
	x = ((void **)seq->array.array)[(seq->head + i) % seq->array.length];
	seq->head = (seq->head + 1) % seq->array.length;
	--seq->length;
	
	// 这个值并没有被实际的删除，所以可以返回其指针
	return x;
}


void *Sequence_addhi(T seq, void *x){
	int i;
	
	assert(seq);
	
	if (seq->length == seq->array.length){
		expand(seq);
	}
	
	i = seq->length++;
	
	return ((void **)seq->array.array)[(seq->head + i) % seq->array.length] = x;
}


void *Sequence_addlo(T seq, void *x){
	int i = 0;
	
	assert(seq);
	
	if (seq->length == seq->array.length){
		expand(seq);
	}
	
	//seq->head = (seq->head - 1) % seq->array.length;
	if (--seq->head < 0){
		seq->head = seq->array.length - 1;
	}
	seq->length++;
	
	return ((void **)seq->array.array)[(seq->head + i) % seq->array.length] = x;
}


static void expand(T seq){
	int n = seq->array.length;
	
	Array_resize(&seq->array, 2 * n);
	if (seq->head > 0){
		// slide tail down	必须处理head位置，否则扩容前的映射全部错位了！
		void **old = &((void **)seq->array.array)[seq->head];
		memcpy(old + n, old, (n-seq->head) * sizeof(void *));
		seq->head += n;
	}
}