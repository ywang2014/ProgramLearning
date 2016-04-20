// ...


#define T Sem_T

// sem functions
T *Sem_new(int count){
	T *s;
	
	NEW(s);
	Sem_init(s, count);
	
	return s;
}

void Sem_init(T *s, int count){
	assert(current);
	assert(s);
	
	s->count = count;
	s->queue = NULL;
}

/////////////////////////////////////////////
/* 语义等价 */
Sem_wait(s):
	
	while (s->count <= 0){
		;
	}
	--s->count;
	
Sem_signal(s):
	
	++s->count;
//////////////////////////////////////////////

// 简明正确，但不合理的实现，忽略了警告和可检查的运行期错误
void Sem_wait(T *s){
	while (s->count <= 0){
		put(current, &s->queue);
		run();
	}
	--s->count;
}

void Sem_signal(T *s){
	if (++s->count > 0 && !isempty(s->queue)){
		put(get(&s->queue), &ready);
	}
}
// 资源竞争，会出现饿死情况


void Sem_wait(T *s){
	assert(current);
	assert(s);
	
	testalert();
	if (s->count <= 0){
		put(currentm (Thread_T *)&s->queue);
		run();
		testalert();
	}
	else{
		--s->count;
	}
}

void Sem_signal(T *s){
	assert(current);
	assert(s);
	
	if (s->count == 0 && !isempty(s->queue)){
		Thread_T t = get((Thread_T *)&s->queue);
		assert(!t->alerted);
		put(t, &ready);
	}
	else{
		++s->count;
	}
}


#undef T 