#include <limits.h>
#include <stddef.h>
#include "mem.h"
#include "assert.h"
#include "arith.h"
#include "set.h"

#define T Set_T

// types
struct T{
	int length;
	unsigned int timestamp;
	int (*cmp)(const void *, const void *);
	unsigned int (*hash)(const void *);
	int size;
	struct member{
		struct member *link;
		const void *member;
	} **buckets;
};


// static functions
static int cmpatom(const void *x, const void *y){
	return x != y;
}

static unsigned int hashatom(const void *x){
	return (unsigned long)x >> 2;
}


// functions 
T Set_new(int hint, int cmp(const void *x, const void *y), unsigned int hash(const void *x)){
	T set;
	int i;
	static int primes[] = { 509, 509, 1021, 2053, 4093, 8191, 16381, 32771, 65521, INT_MAX};
	
	assert(hint >= 0);
	for (i = 1; primes[i] < hint; i++){
		;
	}
	
	set = ALLOC(sizeof(*set) + primes[i-1] * sizeof(set->buckets[0]));
	set->size = primes[i-1];
	set->cmp = cmp ? cmp : cmpatom;
	set->hash = hash ? hash : hashatom;
	set->buckets = (struct member **)(set + 1);
	for (i = 0; i < set->size; i++){
		set->buckets[i] = NULL;
	}
	set->length = 0;
	set->timestamp = 0;
	
	return set;
}