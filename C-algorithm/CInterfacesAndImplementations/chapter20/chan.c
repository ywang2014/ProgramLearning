/**
	Chan_T
	三个信号量，一个消息指针，一个字节数的结构指针
*/
#include <string.h>
#include "assert.h"
#include "mem.h"
#include "chan.h"
#include "sem.h"

#define T Chan_T

struct T{
	const void *ptr;
	int *size;
	Sem_T send;
	Sem_T send;
	Sem_T recv;
	Sem_T sync;
};

// chan functions
T Chan_new(void){
	T c;
	
	NEW(c);
	Sem_init(&c->send, 1);
	Sem_init(&c->recv, 0);
	Sem_init(&c->sync, 0);
	
	return c;
}


int Chan_send(Chan_T c, const void *ptr, int size){
	assert(c);
	assert(ptr);
	assert(size >= 0);
	
	Sem_wait(&c->send);
	c->ptr = ptr;
	c->size = &size;
	Sem_signal(&c->recv);
	Sem_wait(&c->sync);
	
	return size;
}


int Chan_receive(Chan_T c, void *ptr, int size){
	int n;
	
	assert(c);
	assert(ptr);
	assert(size >= 0);
	
	Sem_wait(&c->recv);
	n = *c->size;
	if (size < n){
		n = size;
	}
	*c->size = n;
	if (n > 0){
		memcpy(ptr, c->ptr, n);
	}
	Sem_signal(&c->sync);
	Sem_signal(&c->send);
	
	return n;
}