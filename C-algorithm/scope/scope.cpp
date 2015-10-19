// 数据作用域和存放地址
// 使用MinGW的gcc4.7.1编译的

#include <stdio.h>

int global;	// 全局变量：其他文件可访问，共享
static int file_var = 2;	// 全局静态变量，仅本文件共享

int fun1(void)
{
	int local = 11;	// 局部变量，仅函数内可见可访问
	static int static_var = 11;	// 局部静态，仅函数内共享
	printf("In fun1: \nlocal variable: %p\n", &local);
	printf("static variable: %p\n", &static_var);
	return 0;
}

int fun2(void)
{
	int local = 12;	// 局部变量，仅函数内可见可访问
	static int static_var = 12;	// 局部静态，仅函数内共享
	printf("In fun2: \nlocal variable: %p\n", &local);
	printf("static variable: %p\n", &static_var);
	return 0;
}

int fun3(int i)	// 探究命名规则，c语言不存在，应该看c++
{
	return i;
}

int main(void)
{
	int local = 123;	// 局部变量，仅函数内可见可访问
	static int static_var = 123;	// 局部静态，仅函数内共享
	printf("In main: \nlocal variable: %p\n", &local);
	printf("static variable: %p\n", &static_var);
	fun1();
	fun2();
	
	printf("\n**********************Global**************************\n");
	printf("Global variable: %p\n", &global);
	printf("Global static variable: %p\n", &file_var);
	
	printf("\n**********************Local***************************\n");
	int* ptr_l = &local;
	printf("ptr_l: %p: %d\n", ptr_l, *ptr_l);
	printf("ptr_l+1: %p: %d\n", ptr_l+1, *(ptr_l+1));
	printf("ptr_l+2: %p: %d\n", ptr_l+2, *(ptr_l+2));
	
	printf("\n***********************Global************************\n");
	int* ptr_g = &global;
	printf("ptr_g: %p: %d\n", ptr_g, *ptr_g);
	printf("ptr_g+1: %p: %d\n", ptr_g+1, *(ptr_g+1));
	printf("ptr_g+2: %p: %d\n", ptr_g+2, *(ptr_g+2));
	
	printf("\n***********************Global Static************************\n");
	int* ptr_gs = &file_var;
	printf("ptr_gs: %p: %d\n", ptr_gs, *ptr_gs);
	printf("ptr_gs+1: %p: %d\n", ptr_gs+1, *(ptr_gs+1));
	printf("ptr_gs+2: %p: %d\n", ptr_gs+2, *(ptr_gs+2));
	printf("ptr_gs+3: %p: %d\n", ptr_gs+3, *(ptr_gs+3));
	
	printf("\n************************Function************************\n");
	long* ptr_f = (long*)main;
	printf("ptr_f: %p: %s\n", ptr_f, (char*)ptr_f);
	printf("ptr_f+1: %p: %s\n", ptr_f+1, (char*)(ptr_f+1));
	printf("ptr_f+2: %p: %s\n", ptr_f+2, (char*)(ptr_f+2));
	
	return 0;
}