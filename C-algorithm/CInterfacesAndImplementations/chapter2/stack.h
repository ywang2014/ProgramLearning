/**
	抽象数据类型(ADT)
	
	栈的接口实现 Stack
*/
#ifndef STACK_INCLUDED
#define STACK_INCLUDED

typedef struct Stack_T *Stack_T;

extern Stack_T Stack_new(void);
extern int Stack_empty(Stack_T stk);
extern void Stack_push(Stack_T stk, void *x);
extern void Stack_pop(Stack_T stk);
extern void *Stack_top(Stack_T stk);
extern void Stack_free(Stack_T *stk);

#endif	// STACK_INCLUDED


/***************************************************************/
// 版本二：使用宏将Stack_T在接口内简写为T。

#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#define T Stack_T
typedef struct T *T;

extern T Stack_new(void);
extern int Stack_empty(T stk);
extern void Stack_push(T stk, void *x);
extern void Stack_pop(T stk);
extern void *Stack_top(T stk);
extern void Stack_free(T *stk);

#undef T
#endif