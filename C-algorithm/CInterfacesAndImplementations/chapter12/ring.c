#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "assert.h"
#include "ring.h"
#include "mem.h"

#define T Ring_T

struct T{
	struct node{
		struct node *l_link;
		struct node *r_link;
		void *value;
	} *head;

	int length;
};

// functions
T Ring_new(void){
	T ring;
	
	NEW0(ring);
	ring->head = NULL;
	
	return ring;
}


T Ring_ring(void *x, ...){
	va_list ap;
	T ring = Ring_new();
	
	va_start(ap, x);
	for (; x; x = va_arg(ap, void *)){
		Ring_addhi(ring, x);
	}
	va_end(ap);
	
	return ring;
}


void Ring_free(T *ring){
	struct node *currentNode;
	struct node *nextNode;
	
	assert(ring && *ring);
	
	// 自己构思代码
	// if ((*ring)->head){
		// currentNode = (*ring)->head;
		// while (currentNode != (*ring)->head){
			// nextNode = currentNode->r_link;
			// FREE(currentNode);
			// currentNode = nextNode;
		// }
	// }
	
	// 书中参考代码
	if ((currentNode = (*ring)->head) != NULL){
		int n = (*ring)->length;
		for (; n-- > 0; currentNode = nextNode){
			nextNode = currentNode->r_link;
			FREE(currentNode);
		}
	}
	
	FREE(*ring);
}


int Ring_length(T ring){
	assert(ring);
	
	return ring->length;
}


void *Ring_get(T ring, int i){
	struct node *q;
	
	assert(ring);
	assert(i >= 0 && i < ring->length);
	
	// q <- ith node
	{
		int n;
		q = ring->head;
		if (i <= ring->length / 2){
			for (n = i; n-- > 0; ){
				q = q->r_link;
			}
		}
		else{
			for (n = ring->length - i; n-- > 0; ){
				q = q->l_link;
			}
		}
	}
	
	return q->value;
}


void *Ring_put(T ring, int i, void *x){
	struct node *q;
	void *prev;
	
	assert(ring);
	assert(i >= 0 && i < ring->length);
	
	// q <- ith node
	{
		int n;
		q = ring->head;
		if (i <= ring->length / 2){
			for (n = i; n-- > 0; ){
				q = q->r_link;
			}
		}
		else{
			for (n = ring->length - i; n-- > 0; ){
				q = q->l_link;
			}
		}
	}
	prev = q->value;
	q->value = x;
	
	return prev;	// ? 如何返回的，where
}