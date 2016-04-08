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


void *Ring_addhi(T ring, void *x){
	struct node *p;
	struct node *q;
	
	assert(ring);
	
	NEW(p);
	if ((q = ring->head) != NULL){
		// insert p to the left of q 
		p->l_link = q->l_link;
		p->r_link = q;
		q->l_link->r_link = p;
		q->l_link = p;
		// 千万注意顺序
	}
	else{
		// make p ring's only value 
		ring->head = p->l_link = p->r_link = p;
	}
	ring->length++;
	
	return p->value = x;
}


void *Ring_addlo(T ring, void *x){
	assert(ring);
	
	Ring_addhi(ring, x);
	ring->head = ring->head->l_link;
	
	return x;
}


void *Ring_add(T ring, int pos, void *x){
	assert(ring);
	assert(pos >= -ring->length && pos <= ring->length);
	
	if (pos == 1 || pos == -ring->length){
		return Ring->addlo(ring, x);
	}
	else if (pos == 0 || pos == ring->length + 1){
		return Ring_addhi(ring, x);
	}
	else{
		struct node *p;
		struct node *q;
		int i = pos < 0 ? pos + ring->length : pos - 1;
		
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
		
		NEW(p);
		// insert p to the left of q 
		p->r_link = q;
		p->l_link = q->l_link;
		q->l_link->r_link = p;
		q->l_link = p;
		
		ring->length++;
		
		return p->value = x;
	}
}


void *Ring_remove(T ring, int i){
	void *x;
	struct node *q;
	
	assert(ring);
	assert(ring->length > 0);
	assert(i >= 0 && i < ring->length);
	
	// q <- ith node
	{
		int index;
		q = ring->head;
		
		for (index = i; i > 0; i--){
			q = q->r_link;
		}
	}
	
	if (i == 0){
		// 移动头结点指针
		ring->head = ring->head->r_link;
	}
	x = q->value;
	// delete node q
	{
		q->l_link->r_link = q->r_link;
		q->r_link->l_link = q->l_link;
		FREE(q);
		if (--ring->length == 0){
			ring->head = NULL;
		}
	}
	
	return x;
}


void *Ring_removehi(T ring){
	void *x;
	struct node *q;
	
	assert(ring);
	assert(ring->length > 0);
	
	q = ring->head->l_link;
	x = q->value;
	// delete node q 
	q->l_link->r_link = q->r_link;
	q->r_link->l_link = q->l_link;
	FREE(q);
	if (--ring->length == 0){
		ring->head = NULL;
	}
	
	return x;
}


void *Ring_removelo(T ring){
	assert(ring);
	assert(ring->length > 0);
	
	ring->head = ring->head->rlink;
	
	return Ring_removehi(ring);
}


void Ring_rotate(T ring, int n){
	struct node *q;
	int i;
	
	assert(ring);
	assert(n >= -ring->length && n <= ring->length);
	
	if (n >= 0){
		i = n % ring->length;
	}
	else{
		i = n + ring->length;
	}
	
	// q <- ith node 
	{
		int n;
		q = ring->head;
		
		if (i <= ring->length / 2){
			for (n = i; n > 0; n--){
				q = q->r_link;
			}
		}
		else{
			for (n = ring->length - i; n > 0; n--){
				q = q->l_link;
			}
		}
	}
	ring->head = q;
}