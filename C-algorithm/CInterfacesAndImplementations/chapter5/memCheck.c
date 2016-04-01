/**
	mem接口校验实现
	memCheck.c
*/

#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "except.h"
#include "mem.h"

// checking types
union align{
	int i;
	long l;
	long *lptr;
	void *vptr;
	void (*fp)(void);
	float f;
	double d;
	long double ld;
};

// checking macros
#define hash(p, t) (((unsigned long)(p) >> 3) & (sizeof(t) / sizeof((t)[0]) - 1))

#define NDESCRIPTORS 512

#define NALLOC 4096

// data


// checking data
static struct descriptor{
	struct descriptor *free;
	struct descriptor *link;
	const void *ptr;
	long size;
	const char *file;
	int line;
} *hashTable[2048];

static struct descriptor freelist = { &freelist };

// checking functions
static struct descriptor *find(const void *ptr){
	struct descriptor *bp = hashTable[hash(ptr, hashTable)];
	
	while (bp && bp->ptr != ptr){
		bp = bp->link;
	}
	
	return bp;
}


void Mem_free(void *ptr, const char *file, int line){
	if (ptr){
		struct descriptor *bp;
		
		if (((unsigned long)ptr) % (sizeof(union align)) != 0 || 
			(bp = find(ptr)) == NULL ||
			bp->free){
			Except_raise(&Assert_Failed, file, line);
		}
		
		bp->free = freelist.free;
		freelist.free = bp;
	}
}


void *Mem_resize(void *ptr, long nbytes, const char *file, int line){
	struct descriptor *bp;
	void *newptr;
	
	assert(ptr);
	assert(nbytes > 0);
	
	if (((unsigned long)ptr) % (sizeof(union align)) != 0 || 
		(bp = find(ptr)) == NULL ||
		bp->free){
		Except_raise(&Assert_Failed, file, line);
	}
		
	newptr = Mem_alloc(nbytes, file, line);
	// memcpy()
	memcpy(newptr, ptr, (nbytes < bp->size) ? nbytes : bp->size);
	Mem_free(ptr, file, line);
	
	return newptr;
}


void *Mem_calloc(long count, long nbytes, const char *file, int line){
	void *ptr;
	
	assert(count > 0);
	assert(nbytes > 0);
	
	ptr = Mem_alloc(count * nbytes, file, line);
	// memset()
	memset(ptr, '\0', count * nbytes);
	
	return ptr;
}


static struct descriptor *dalloc(void *ptr, long size, const char *file, int line){
	static struct descriptor *avail;
	static int nleft;
	
	if (nleft <= 0){
		// allocate descriptors
		avail = malloc(NDESCRIPTORS * sizeof(*avail));
		if (avail == NULL){
			return NULL;
		}
		
		nleft = NDESCRIPTORS;
	}
	avail->ptr = ptr;
	avail->size = size;
	avail->file = file;
	avail->line = line;
	avail->free = avail->link = NULL;
	nleft--;
	
	return avail++;
}


void *Mem_alloc(long nbytes, const char *file, int line){
	struct descriptor *bp;
	void *ptr;
	
	assert(nbytes > 0);
	
	// round nbytes up to an alignment boundary 
	nbytes = ((nbytes + sizeof(union align) - 1) / (sizeof(union align))) * (sizeof(union align));
	
	for (bp = freelist.free; bp; bp = bp->free){
		if (bp->size > nbytes){
			// use the end of the block at bp 
			bp->size -= nbytes;
			ptr = (char *)bp->str + bp->size;
			if ((bp = dalloc(ptr, nbytes, file, line)) != NULL){
				unsigned int h = hash(ptr, hashTable);
				bp->link = hashTable[h];
				hashTable[h] = bp;
				return ptr;
			}
			else{
				// raise Mem_Failed
				if (((unsigned long)ptr) % (sizeof(union align)) != 0 || 
					(bp = find(ptr)) == NULL ||
					bp->free){
					Except_raise(&Assert_Failed, file, line);
				}
			}
		}
		
		if (bp == &freelist){
			struct descriptor *newptr;
			// newptr <- a block of size NALLOC + bnytes
			if ((ptr = malloc(nbytes + NALLOC)) == NULL || 
				(newptr = dalloc(ptr, nbytes + NALLOC, __FILE__, __LINE__)) == NULL){
				// raise Mem_Failed
				if (((unsigned long)ptr) % (sizeof(union align)) != 0 || 
					(bp = find(ptr)) == NULL ||
					bp->free){
					Except_raise(&Assert_Failed, file, line);
				}
			}
			
			newptr->free = freelist.free;
			freelist.free = newptr;
		}
	}
	
	assert(0);
	return NULL;
}
