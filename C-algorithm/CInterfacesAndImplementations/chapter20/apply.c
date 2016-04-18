/**
	如下形式的额函数，可以终止线程
*/

int apply(void *p){
	TRY
		...
	EXCEPT (Thread_Alerted)
		Thread_exit(EXIT_FAILURE);
	END_TRY;
	Thread_exit(EXIT_SUCCESS);
}

// TRY-EXCEPT 用于调用线程，而不是创建线程