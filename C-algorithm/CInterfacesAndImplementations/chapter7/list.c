#include <stdarg.h>
#include <stddef.h>
#include "assert.h"
#include "mem.h"
#include "list.h"

#define T List_T

// functions
T List_push(T list, void *x){
	T p;
	
	NEW(P);
	p->first = x;
	p->rest = list;
	
	return p;
}


T List_list(void *x, ...){
	va_list ap;
	T list;
	T *p = &list;
	
	va_start(ap, x);
	for (; x; x = va_arg(ap, void *)){
		NEW(*p);
		(*p)->first = x;
		p = &((*p)->rest);
	}
	*p = NULL;
	va_end(ap);
	
	return list;
}


T List_append(T list, T tail){
	T *p = &list;
	
	while (*p){
		p = &((*p)->rest);
	}
	*p = tail;
	return list;
}


T List_copy(T list){
	T head;
	T *p = &head;
	
	for (; list; list = list->rest){
		NEW(*p);
		(*p)->first = list->first;
		p = &((*p)->rest);
	}
	*p = NULL;
	return head;
	/*
		指针返回的只是地址，head是局部隐藏指针，指向的是堆空间，而不是指向局部变量的指针。
		返回局部指针是没有问题的，因为指针地址是不会变的，不随着栈空间变化而变化。
		栈空间变化的是其值(内容)，因局部变量在函数返回后，可能会被覆盖，所以不能返回局部变量的指针和引用，
		因为指针指向的内容，常是垃圾值，但指针地址是没有错的。
	*/
}


T List_pop(T list, void **x){
	if (list){
		T head = list->rest;
		if (x){
			*x = list->first;
		}
		
		FREE(list);
		return head;
	}
	else{
		return list;
	}
}


T List_reverse(T list){
	T head = NULL;
	T = next;
	
	for (; list; list = next){
		next = list->rest;
		list->rest = head;
		head = list;
	}
	
	return head;
}


int List_length(T list){
	int n;
	
	for (n = 0; list; list = list->rest){
		n++;
	}
	
	return n;
}


void List_free(T *list){
	T next;
	
	assert(list);
	
	for (; *list; *list = next){
		next = (*list)->rest;
		FREE(*list);
	}
}


void List_map(T list, void apply(void **x, void *c1), void *c1){
	assert(apply);
	for (; list; list = list->rest){
		apply(&list->first, c1);
	}
}


void **List_toArray(T list, void *end){
	int i;
	int n = List_length(list);
	void **array = ALLOC((n + 1) * sizeof(*array));
	
	for (i = 0; i < n; i++){
		array[i] = list->first;
		list = list->rest;
	}
	
	array[i] = end;
	return array;
}