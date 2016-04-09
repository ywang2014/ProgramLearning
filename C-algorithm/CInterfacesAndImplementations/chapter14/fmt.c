#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <math.h>
#include "assert.h"
#include "except.h"
#include "fmt.h"
#include "mem.h"

#define T Fmt_T

// types
struct buf{
	char *buf;
	char *bp;
	int size;
};

// macros

//conversion functions
static void cvt_d(int code, va_list *app,
	int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	int val = va_arg(*app, int);
	unsigned int m;
	// declare buf and p, initialize p 
	char buf[43];
	char *p = buf + sizeof(buf);
	
	if (val == INT_MIN){
		m = INT_MAX + 1U;
	}
	else if (val < 0){
		m = -val;
	}
	else{
		m = val;
	}
	
	do{
		*--p = m % 10 + '0';
	}
	while ((m /= 10) > 0);
	if (val < 0){
		*--p = '-';
	}
	
	Fmt_putd(p, (buf + sizeof(buf)) - p, put, c1, flags, width, precision);
}


static void cvt_u(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	
	unsigned m = va_arg(*app, unsigned);
	// declare buf and p, initialize p
	char buf[43];
	char *p = buf + sizeof(buf);
	
	do{
		*--p = m % 10 + '0';
	} while ((m / 10) > 0);
	
	Fmt_putd(p, (buf + sizeof(buf)) - p, put, c1, flags, width, precision);
}


static void cvt_o(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	
	unsigned m = va_arg(*app, unsigned);
	// declare buf and p, initialize p 
	char buf[43];
	char *p = buf + sizeof(buf);
	
	do{
		*--p = (m & 0x7) + '0';	// 0x7(0111)
	} while ((m >>= 3) != 0);
	
	Fmt_putd(p, (buf + sizeof(buf)) - p, put, c1, flags, width, precision);
}


static void cvt_x(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	
	unsigned m = va_arg(*app, unsigned);
	// declare buf and p, initialize p 
	char buf[43];
	char *p = buf + sizeof(buf);
	
	// emit m in hexadecimal
	do{
		*--p = "0123456789abcdef"[m & 0xf];
	} while ((m >>= 4) != 0);
	
	Fmt_putd(p, (buf + sizeof(buf)) - p, put, c1, flags, width, precision);
}


static void cvt_p(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	
	unsigned long m = (unsigned long)va_arg(*app, void *);
	// declare buf and p, initialize p 
	char buf[43];
	char *p = buf + sizeof(buf);
	
	precision = INT_MIN;
	// emit m in hexadecimal
	do{
		*--p = "0123456789abcdef"[m & 0xf];
	} while ((m >>= 4) != 0);
	
	Fmt_putd(p, (buf + sizeof(buf)) - p, put, c1, flags, width, precision);
}


static void cvt_c(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	// normalize width
	
	if (!flags['-']){
		pad(width - 1, ' ');
	}
	
	put((unsigned char)va_arg(*app, int), c1);
	
	if (flags['-']){
		pad(width - 1, ' ');
	}
}


static void cvt_f(int code, va_list *app, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	
	char buf[DBL_MAX_10_EXP + 1 + 1 + 99 + 1];	// DBL_MAX_10_EXP=308
	
	if (precision < 0){
		precision = 6;
	}
	
	if (code == 'g' && precision == 0){
		precision = 1;
	}
	
	// format a double argument into buf
	{
		static char fmt[] = "%.dd?";
		assert(precision <= 99);
		fmt[4] = code;
		fmt[3] = precision % 10 + '0';
		fmt[2] = (precision / 10) % 10 + '0';
		sprintf(buf, fmt, va_arg(*app, double));
	}
	
	Fmt_putd(buf, strlen(buf), put, c1, flags, width, precision);
}




// data
const Except_T Fmt_Overflow = { "Formatting Overflow" };

static T cvt[256] = {
	0, 		0, 0, 0, 		0, 		0, 		0, 		0,		/* 0  -  7 */
	0, 		0, 0, 0, 		0, 		0, 		0, 		0,		/* 8  - 15 */
	0, 		0, 0, 0, 		0, 		0, 		0, 		0,		/* 16 - 23 */
	0,		0, 0, 0, 		0, 		0, 		0, 		0,		/* 24 - 31 */
	0, 		0, 0, 0, 		0, 		0, 		0, 		0,		/* 32 - 39 */
	0, 		0, 0, 0, 		0, 		0, 		0, 		0,		/* 40 - 47 */
	0, 		0, 0, 0, 		0, 		0,	 	0, 		0,		/* 48 - 55 */
	0, 		0, 0, 0, 		0, 		0, 		0, 		0,		/* 56 - 63 */
	0,		0, 0, 0, 		0, 		0, 		0,	 	0,		/* 64 - 71 */
	0,		0, 0, 0, 		0, 		0, 		0, 		0,		/* 72 - 79 */
	0,		0, 0, 0, 		0, 		0, 		0, 		0,		/* 80 - 87 */
	0, 		0, 0, 0, 		0, 		0, 		0, 		0,		/* 88 - 95 */
	0, 		0, 0, cvt_c, 	cvt_d, 	cvt_f, 	cvt_f, 	cvt_f,	/* 96 -103 */
	0, 		0, 0, 0, 		0, 		0, 		0, 		cvt_o,	/* 104-111 */
	cvt_p, 	0, 0, cvt_s, 	0, 		cvt_u, 	0, 		0,		/* 112-119 */
	cvt_x, 	0, 0, 0, 		0, 		0, 		0, 		0,		/* 120-127 */
};

char *Fmt_flags = "-+ 0";

// static functions
static int outc(int c, void *c1){
	FILE *f = c1;
	
	return putc(c, f);
}


static int insert(int c, void *c1){
	struct buf *p = c1;
	
	if (p->bp >= p->buf + p->size){
		RAISE(Fmt_Overflow);
	}
	*((p->bp)++) = c;
	
	return c;
}


static int append(int c, void *c1){
	struct buf *p = c1;
	
	if (p->bp >= p->buf + p->size){
		RESIZE(p->buf, 2 * p->size);
		p->bp = p->buf + p->size;
		p->size *= 2;
	}
	*((p->bp)++) = c;
	
	return c;
}


// functions
void Fmt_fmt(int put(int c, void *), void *c1, const char *fmt, ...){
	va_list ap;
	
	va_start(ap, fmt);
	Fmt_vfmt(put, c1, fmt, ap);
	va_end(ap);
}


void Fmt_print(const char *fmt, ...){
	va_list ap;
	
	va_start(ap, fmt);
	Fmt_vfmt(outc, stdout, fmt, ap);
	va_end(ap);
}


void Fmt_fprint(FILE *stream, const char *fmt, ...){
	va_list ap;
	
	va_start(ap, fmt);
	Fmt_vfmt(outc, stream, fmt, ap);
	va_end(ap);
}


int Fmt_sfmt(char *buf, int size, const char *fmt, ...){
	va_list ap;
	int len;
	
	va_start(ap, fmt);
	len = Fmt_vsfmt(buf, size, fmt, ap);
	va_end(ap);
	
	return len;
}


int Fmt_vsfmt(char *buf, int size, const char *fmt, va_list ap){
	struct buf c1;
	
	assert(buf);
	assert(size > 0);
	assert(fmt);
	
	c1.buf = c1.bp = buf;
	c1.size = size;
	
	Fmt_vfmt(insert, &c1, fmt, ap);
	insert(0, &c1);
	
	return c1.bp - c1.buf - 1;
}


char *Fmt_string(const char *fmt, ...){
	char *str;
	va_list ap;
	
	assert(fmt);
	
	va_start(ap, fmt);
	str = Fmt_vstring(fmt, ap);
	va_end(ap);
	
	return str;
}


char *Fmt_vstring(const char *fmt, va_list ap){
	struct buf c1;
	
	assert(fmt);
	
	c1.size = 256;
	c1.buf = c1.bp = ALLOC(c1.size);
	
	Fmt_vfmt(append, &c1, fmt, ap);
	append(0, &c1);
	
	return RESIZE(c1.buf, c1.bp - c1.buf);
}


void Fmt_vfmt(int put(int c, void *c1), void *c1, const char *fmt, va_list ap){
	assert(put);
	assert(fmt);
	
	while (*fmt){
		if (*fmt != '%' || *++fmt == '%'){
			put((unsigned char *)*fmt++, c1);
		}
		else{
			// format an argument
			unsigned char c;
			unsigned char flags[256];
			int width = INT_MIN;
			int precision = INT_MIN;
			
			memset(flags, '\0', sizeof(flags));
			
			// get optional flags
			if (Fmt_flags){
				unsigned char c = *fmt;
				// extern char *strchr(const char *s,char c) 查找字符串s中首次出现字符c的位置
				for (; c && strchr(Fmt_flags, c); c = *++fmt){
					assert(flags[c] < 255);
					flags[c]++;
				}
			}
			
			// get optional field width
			if (*fmt == '*' || isdigit(*fmt)){
				int n;
				// n <- next argument or scan digits
				if (*fmt == '*'){
					n = va_arg(ap, int);
					assert(n != INT_MIN);
					fmt++;
				}
				else
				{
					for (n = 0; isdigit(*fmt); fmt++){
						int d = *fmt - '0';
						assert(n <= (INT_MAX - d) / 10);
						n = 10 * n + d;
					}
				}
				
				width = n;
			}
			
			// get optional precision 
			if (*fmt == '.' && (*++fmt == '*' || isdigit(*fmt))){
				int n;
				// n <- next argument or sacn digits 
				if (*fmt == '*'){
					n = va_arg(ap, int);
					assert(n != INT_MIN);
					fmt++;
				}
				else
				{
					for (n = 0; isdigit(*fmt); fmt++){
						int d = *fmt - '0';
						assert(n <= (INT_MAX - d) / 10);
						n = 10 * n + d;
					}
				}
				
				precision = n;
			}
			
			c = *fmt++;
			assert(cvt[c]);
			(*cvt[c])(c, &ap, put, c1, flags, width, precision);
		}
	}
}


T Fmt_register(int code, T newcvt){
	T old;
	
	assert(0 < code && code < (int)(sizeof(cvt) / sizeof(cvt[0])));
	
	old = cvt[code];
	cvt[code] = newcvt;
	
	return old;
}


void Fmt_putd(const char *str, int len, int put(int c, void *c1), void *c1,
	unsigned char flags[], int width, int precision){
	int sign;
	
	assert(str);
	assert(len >= 0);
	assert(flags);
	
	// normalize width and flags 
	
	// compute the sign 
	if (len > 0 &&(*str == '-' || *str == '+')){
		sign = *str++;
		len--;
	}
	else if (flags['+']){
		sign = '+';
	}
	else if (flags[' ']){
		sign = ' ';
	}
	else{
		sign = 0;
	}
	
	{
		// emit str justified in width
		int n;
		if (precision < 0){
			precision = 1;
		}
		
		if (len < precision){
			n = precision;
		}
		else if (precision == 0 && len == 1 && str[0] == '0'){
			n = 0;
		}
		else{
			n = len;
		}
		
		if (sign){
			n++;
		}
		
		if (flags['-']){
			//emit the sign 
			if (sign){
				put(sign, c1);
			}
		}
		else if (flags['0']){
			// emit the sign 
			if (sign){
				put(sign, c1);
			}
			
			pad(width - n, '0');
		}
		else{
			pad(width - n, ' ');
			// emit the sign 
			if (sign){
				put(sign, c1);
			}
		}
		
		pad(precison - len, '0');
		// emit str[0...len-1]
		
		if (flags['-']){
			pad(width - n, ' ');
		}
	}
}