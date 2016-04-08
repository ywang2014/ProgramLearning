/*
	Bit_T 是带有位向量的长度和比特本身的结构指针
*/
#incldue <stdarg.h>
#include <string.h>
#include "assert.h"
#include "bit.h"
#include "mem.h"

#define T Bit_T

struct T{
	int length;
	unsigned char *bytes;
	unsigned long *words;
};

// macros
#define BPW (8 * sizeof(unsigned long))

#define nwords(len) ((((len) + BPW - 1) & (~(BPW - 1))) / BPW)

// &(~(8-1)) 为了右端对齐，得到8的整数倍 (内存操作，分页操作中，都需要对齐)
// +7 为了向上取整
#define nbytes(len) ((((len) + 8 - 1) & (~(8 - 1))) / 8)


// static data
// lo%8 索引掩码表 0位，则所有的设置为1(0xFF)，...，7位则仅最高位设置为1(0x80)
unsigned char msbmask[] = { // most significant bit 
	0xFF, 0xFE, 0xFC, 0xF8,
	0xF0, 0xE0, 0xC0, 0x80,
};

unsigned char lsbmask[] = {
	0x01, 0x03, 0x07, 0x0F,
	0x1F, 0x3F, 0x7F, 0xFF,
};


// static functions


// functions
T Bit_new(int length){
	T set;
	
	assert(length >= 0);
	
	NEW(set);
	if (length > 0){
		set->words = CALLOC(nwords(length), sizeof(unsigned long));
	}
	else{
		set->words = NULL;
	}
	
	set->bytes = (unsigned char *)set->words;
	set->length = length;
	
	return set;
}


void Bit_free(T *set){
	assert(set && *set);
	
	FREE((*set)->words);
	FREE(*set);
}


int Bit_length(T set){
	assert(set);
	
	return set->length;
}


int Bit_count(T set){
	int length = 0;
	int n;
	static char count[] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
	
	assert(set);
	
	//for (n = nbytes(set->length); n >= 0; n--){	// 存在副作用，除非n初始减1
	for (n = nbytes(set->length); --n >= 0; ){
		unsigned char ch = set->bytes[n];
		length += count[ch & 0xF] + count[ch >> 4];
	} 
	
	return length;
}


int Bit_get(T set, int n){
	assert(set);
	assert(0 <= n && n < set->length);
	
	// bit n in set 	n/8表示在第几个字节中，n%8表示字节中的第几位
	return ((set->bytes[n/8] >> (n % 8)) & 1);
}

int Bit_put(T set, int n, int bit){
	int prev;
	
	assert(set);
	assert(bit == 0 || bit == 1);
	assert(0 <= n && n < set->length);
	
	prev = ((set->bytes[n/8] >> (n % 8)) & 1);
	if (bit == 1){
		set->bytes[n/8] |= (1 << (n % 8));
	}
	else{
		set->bytes[n/8] &= (~(1 << (n % 8)));
	}
	
	return prev;
}


void Bit_set(T set, int lo, int hi){
	// check set, lo, hi
	assert(set);
	assert(0 <= lo && hi < set->length);
	assert(lo <= hi);
	
	if ((lo / 8) < (hi / 8)){
		// set the most significant bits in byte lo/8
		set->bytes[lo/8] |= msbmask[lo%8];
		
		// set all the bits in bytes lo/8+1...hi/8-1
		{
			int i;
			for (i = lo/8+1; i < hi/8; i++){
				// 整个字节所有bit位设置为1
				set->bytes[i] = 0xFF;
			}
		}
		
		// set the least significant bits in byte hi/8
		set->bytes[hi/8] |= lsbmask[hi%8];
	}
	else{
		// set bits lo%8...hi%8 in byte lo/8 
		// mask for bits lo%8...hi%8
		set->bytes[lo/8] |= (msbmask[lo%8] & lsbmask[hi%8]);
	}
}


void Bit_clear(T set, int lo, int hi){
	// check set, lo, hi
	assert(set);
	assert(0 <= lo && hi < set->length);
	assert(lo <= hi);
	
	if ((lo / 8) < (hi / 8)){
		int i;
		set->bytes[lo/8] &= ~msbmask[lo%8];
		for (i = lo/8 + 1; i < hi/8; i++){
			set->bytes[i] = 0;
		}
		set->bytes[hi/8] &= ~lsbmask[hi%8];
	}
	else{
		// mask for bits lo%8...hi%8
		set->bytes[lo/8] &= ~(msbmask[lo%8] & lsbmask[hi%8]);
	}
}


void Bit_not(T set, int lo, int hi){
	// check set, lo, hi
	assert(set);
	assert(0 <= lo && hi < set->length);
	assert(lo <= hi);
	
	if ((lo / 8) < (hi / 8)){
		int i;
		set->bytes[lo/8] ^= msbmask[lo%8];
		for (i = lo/8+1; i < hi/8; i++){
			set->bytes[lo/8] ^= 0xFF;
		}
		set->bytes[hi/8] ^= lsbmask[hi%8];
	}
	else{
		// mask for bits lo%8...hi%8
		set->bytes[lo/8] ^= (msbmask[lo%8] & lsbmask[hi%8])
	}
}


void Bit_map(T set, void apply(int n, int bit, void *c1), void *c1){
	int n;
	
	assert(set);
	assert(apply);
	
	for (n = 0; n < set->length; n++){
		// bit n in set
		apply(n, ((set->bytes[n/8] >> (n % 8)) & 1), c1);
	}
}


int Bit_eq(T s, T t){
	int i;
	
	assert(s && t);
	assert(s->length == t->length);
	
	for (i = nwords(s->length; --i >= 0; ){
		if (s->words[i] != t->words[i]){
			return 0;
		}
	}
	
	return 1;	// 相等
}