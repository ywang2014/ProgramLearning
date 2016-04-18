/**
	临界区
*/
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "fmt.h"
#include "thread.h"
#include "sem.h"

#define NBUMP 30000

// spin types
struct args{
	Sem_T *mutex;
	int *ip;
};


// spin functions
int unsafe(void *c1){
	int i;
	int *ip = c1;
	
	for (i = 0; i < NBUMP; i++){
		*ip = *ip + 1;	// 不安全，可能被中断
	}
	
	return EXIT_SUCCESS;
}

int safe(void *c1){
	struct args *p = c1;
	int i;
	
	for (i = 0; i < NBUMP; i++){
		LOCK(*p->mutex)
			*p->ip = *ip->ip + 1;
		END_LOCK;
		// 就是做操作的时候，加锁
	}
	
	return EXIT_SUCCESS;
}


int n;
int main(int argc, char *argv[]){
	int m = 5;
	int preempt;
	
	preempt = Thread_init(1, NULL);
	assert(preempt == 1);
	if (argc >= 2){
		m = atoi(argv[1]);
	}
	n = 0;
	// increment n unsafely
	{
		int i;
		for (i = 0; i < m; i++){
			Thread_new(unsafe, &n, 0, NULL);	// 创建m个线程
		}
		Thread_join(NULL);
	}
	
	Fmt_print("%d == %d\n", n, NBUMP * m);
	
	n = 0;
	// increment n safely
	{
		int i;
		struct args args;
		Sem_T mutex;
		Sem_init(&mutex, 1);
		args.mutex = &mutex;
		args.ip = &n;
		for (i = 0; i < m; i++){
			Thread_new(safe, &args, sizeof(args), NULL);
		}
		Thread_join(NULL);
	}
	
	Fmt_print("%d == %d\n", n, NBUMP * m);
	Thread_exit(EXIT_SUCCESS);
	
	return EXIT_SUCCESS;
}
