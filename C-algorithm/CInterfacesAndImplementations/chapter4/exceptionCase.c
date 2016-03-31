/**
	C语言中结构化异常工具的基础
	
	setjmp		实例化处理程序
	longjmp		产生异常
*/

#include <setjmp.h>

int Allocation_handled = 0;
jmp_buf Allocate_Failed;

void *allocate(unsigned int n){
	void *new = malloc(n);
	
	if (new){
		return new;
	}
	
	if (Allocation_handled){
		longjmp(Allocate_Failed, 1);
	}
	
	assert(0);
}


char *buf;
Allocation_handled = 1;
if (setjmp(Allocate_Failed)){
	fprintf(stderr, "couldn't allocate the buffer\n");
	exit(EXIT_FAILURE);
}
buf = allocate(4096);
Allocation_handled = 0;