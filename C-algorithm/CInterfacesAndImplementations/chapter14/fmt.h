/**
	Format interface
	C标准库函数:
		printf: 将数据格式化到控制台，显示器
			extern void printf(const char *format, ...);
		
		fprintf(vfprintf): 将数据格式化到流/文件(FILE *, stdout, stderr)
			int fprintf (FILE* stream, const char *format, ...)
			
		vprintf: stdout
			printf的功能就是用它来实现的，所不同的是，它用一个参数取代了变长参数表，且此参数是通过调用va_start宏进行初始化
			int vprintf(char *format, va_list param);
			
		sprintf(vsprintf): 将数据格式化到字符串缓冲区
			int sprintf(char *buffer, const char *format, ...);
			
	存在问题：
		1.转换说明符的设置是固定的，无法提供专门基于用户程序的灵活性
		2.被格式化的结果，只能在字符串中被打印或存储，无法定义基于用户程序的输出程序
		3.sprintf、vsprintf是不安全的，可能试图输出比缓冲区能够存储的字符，更多的字符
		4.参数列表的变量部分，传递的参数无法进行格式检查
*/
#ifndef FMT_INCLUDED
#define FMT_INCLUDED

#include <stdarg.h>
#include <stdio.h>
#include "except.h"

#define T Fmt_T

typedef void (*T)(int code, va_list *app, int put(int c, void *c1), void *c1, 
	unsigned char flags[256], int width, int precision);
	
extern char *Fmt_flags;
extern const Except_T Fmt_Overflow;

// exported functions
extern void Fmt_fmt(int put(int c, void *c1), void *c1, const char *fmt, ...);
extern void Fmt_vfmt(int put(int c, void *c1), void *c1, const char *fmt, va_list ap);

extern void Fmt_print(const char *fmt, ...);
extern void Fmt_fprint(FILE *stream, const char *fmt, ...);
extern int Fmt_sfmt(char *buf, int size, const char *fmt, ...);
extern int Fmt_vsfmt(char *buf, int size, const char *fmt, va_list ap);

extern char *Fmt_string(const char *fmt, ...);
extern char *Fmt_vstring(const char *fmt, va_list ap);

extern T Fmt_register(int code, T cvt);

extern void Fmt_putd(const char *str, int len, int put(int c, void *c1), void *c1, 
	unsigned char flags[256], int width, int precision);
extern void Fmt_puts(const char *str, int len, int put(int c, void *c1), void *c1,
	unsigned char flags[256], int width, int precision);


#undef T
#endif