/**
	Stack 接口的实现
*/

#include <stddef.h>
#include "assert.h"
#include "mem.h"
#include "stack.h"

#define T Stack_T

struct T{
	int count;		// 指针的计数
	struct elem{
		void *x;
		struct elem *link;
	} *head;		// 指向栈内指针的链表
};


T Stack_new(void){
	T stk;
	
	// Mem接口中一个分配宏指令
	NEW(stk);		
	stk->count = 0;
	stk->head = NULL;
	return stk;
}


int Stack_empty(T stk){
	// 断言实现可检查的运行时错误，禁止空指针传递给函数		assert(e) 说明e不为0，否则如果e为0，停止程序的运行
	assert(stk);	
	return stk->count == 0;
}


void Stack_push(T stk, void *x){
	struct elem *t;
	
	assert(stk);
	NEW(t);
	t->x = x;
	t->link = stk->head;
	stk->head = t;
	stk->count++;
}


void Stack_pop(T stk){
	struct elem* data;	// 声明一个节点，用于删除(C语言，必须先声明)
	
	assert(stk);
	data = stk->head;
	stk->head = data->link;
	stk->count--;
	// Mem接口中的释放宏指令，释放参数所指向的空间，并将参数设为空指针，避免出现悬空指针
	FREE(data);
}


void *Stack_top(T stk){
	assert(stk);
	return stk->head->x;
}


void Stack_free(T *stk){
	struct elem *t, *u;
	
	assert(stk && *stk);
	for (t = (*stk)->head; t != NULL; t = u){
		u = t->link;
		FREE(t);
	}
	FREE(*stk);
}