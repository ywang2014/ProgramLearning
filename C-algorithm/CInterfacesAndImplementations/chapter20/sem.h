/**
	semaphore interface
	
	signal() 逻辑上等价于原子性的增加
	wait(s) 等待s为正，然后进行原子性的消减
*/
#ifndef SEM_INCLUDED
#define SEM_INCLUDED

#define T Sem_T
typedef struct T{
	int count;
	void *queue;
};

// exported macros
#define LOCK(mutex)	do{ \
	Sem_T *_yymutex = &(mutex);	\
	Sem_wait(_yymutex);
#define END_LOCK Sem_signal(_yymutex); \
} while (0)
// 锁的实现，实际就是信号量的 wait/signal

extern void Sem_init(T *s, int count);
extern T *Sem_new(int count);
extern void Sem_wait(T *s);
extern void Sem_signal(T *s);


#undef T 
#endif