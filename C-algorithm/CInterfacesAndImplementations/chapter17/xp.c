#include <ctype.h>
#include <string.h>
#include "assert.h"
#include "xp.h"

#define T XP_T
#define BASE (1 << 8)

// *p is a digit in base
#define isBaseDigit(p) ((p) && isalnum(p) && map[(p) - '0'] < base)

// data
static char map[] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	36, 36, 36, 36, 36, 36, 36,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35,
	36, 36, 36, 36, 36, 36,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35
};


// functions 
unsigned long XP_fromint(int n, T z, unsigned long u){
	int i = 0;
	
	do{
		z[i++] = u % BASE;
	} while ((u /= BASE) > 0 && i < n);
	
	for (; i < n; i++){
		z[i] = 0;
	}
	
	return u;
}


unsigned long XP_toint(int n, T x){
	unsigned long u = 0;
	int i = (int)sizeof(u);
	
	if (i > n){
		i = n;
	}
	
	// 溢出部分，被舍弃
	while (--i >= 0){
		u = BASE * u + x[i];
	}
	
	return u;
}


int XP_length(int n, T x){
	while (n > 1 && x[n - 1] == 0){
		n--;
	}
	
	return n;
}


int XP_add(int n, T z, T x, T y, int carry){
	int i;
	
	for (i = 0; i < n; i++){
		carry += x[i] + y[i];
		z[i] = carry % BASE;
		carry /= BASE;
	}
	
	return carry;
}


int XP_sub(int n, T z, T x, T y, int borrow){
	int i;
	
	for (i = 0; i < n; i++){
		int d = (x[i] + BASE) - borrow - y[i];
		z[i] = d % BASE;
		borrow = 1 - d / BASE;
	}
	
	return borrow;
}


int XP_sum(int n, T z, T x, int y){
	int i;
	
	for (i = 0; i < n; i++){
		y += x[i];				// 理论上对y没有大小限制的，但是必须考虑整形溢出的问题！
		z[i] = y % BASE;
		y /= BASE;
	}
	
	return y;
}


int XP_diff(int n, T z, T x, int y){
	int i;
	
	for (i = 0; i < n; i++){
		y = x[i] + BASE - y;
		z[i] = y % BASE;
		y = 1 - y / BASE;
	}
}


int XP_neg(int n, T z, T x, int carry){
	int i;
	
	for (i = 0; i < n; i++){
		carry += (unsigned char)~x[i];
		z[i] = carry % BASE;
		carry /= BASE;
	}
	
	return carry;
}


int XP_mul(T z, int n, T x, int m, T y){
	int i;
	int j;
	int carryout = 0;
	
	for (i = 0; i < n; i++){
		unsigned int carry = 0;
		for (j = 0; j < m; j++){
			carry += x[i] * y[j] + z[i + j];
			z[i + j] = carry % BASE;
			carry /= BASE;
		}
		
		for (; j < n + m - i; j++){
			carry += z[i + j];
			z[i + j] = carry % BASE;
			carry /= BASE;
		}
		carryout |= carry;
	}
	
	return carryout;
}


int XP_product(int n, T z, T x, int y){
	int i;
	unsigned int carry = 0;
	
	for (i = 0; i < n; i++){
		carry += x[i] * y;
		z[i] = carry % BASE;
		carry /= BASE;
	}
	
	return carry;
}


int XP_div(int n, T q, T x, int m, T y, T r, T tmp){
	int nx = n;
	int my = m;
	
	n = XP_length(n, x);
	m = XP_length(m, y);
	if (m == 1){
		// single-digit division
		if (y[0] == 0){
			return 0;
		}
		r[0] = XP_quotient(nx, q, x, y[0]);
		memset(r + 1, '\0', my - 1);
	}
	else if (m > n){
		memset(q, '\0', nx);
		memcpy(r, x, n);
		memset(r + n, '\0', my - n);
	}
	else{
		// long division 
		int k;
		unsigned char *rem = tmp;
		unsigned char *dq = tmp + n + 1;
		
		assert(2 <= m && m <= n);
		
		memcpy(rem, x, n);
		rem[n] = 0;
		for (k = n - m; k >= 0; k--){
			int qk;
			// compute qk, dq <-- y*qk 
			{
				int i;
				assert(2 <= m && m <= k + m; && k + m <= n);
				// qk <-- y[m-2...m-1]/rem[k+m-2...k+m]
				{
					int km = k + m;
					unsigned long y2 = y[m - 1] * BASE + y[m - 2];
					unsigned long r3 = rem[km] * (BASE * BASE) + rem[km - 1] * BASE + rem[km - 2];
					
					qk = r3 / y2;
					if (qk >= BASE){
						qk = BASE - 1;
					}
				}
				
				for (i = m; i > 0; i--){
					if (rem[i + k] != dq[i]){
						break;
					}
				}
				if (rem[i + k] < dq[i]){
					dq[m] = XP_product(m, dq, y, --qk);
				}
			}
			
			q[k] = qk;
			// rem <-- rem - dq*b^k 
			{
				int borrow;
				assert(0 <= k && k <= k + m);
				borrow = XP_sub(m + 1, &rem[k], &rem[k], dq, 0);
				assert(borrow == 0);
			}
		}
		memcpy(r, rem, m);
		// fill out q and r with 0s 
		{
			int i = 0;
			for (i = n - m + 1; i < nx; i++){
				q[i] = 0;
			}
			
			for (i = m; i < my; i++){
				r[i] = 0;
			}
		}
	}
	
	return 1;
}


int XP_quotient(int n, T z, T x, int y){
	int i;
	unsigned carry = 0;
	
	for (i = n - 1; i >= 0; i--){
		carry = carry * BASE + x[i];
		z[i] = carry / y;
		carry %= y;
	}
	
	return carry;
}


int XP_cmp(int n, T x, T y){
	int i = n - 1;
	
	while (i > 0 && x[i] == y[i]){
		i--;
	}
	
	return x[i] - y[i];
}


void XP_lshift(int n, T z, int m, T x, int s, int fill){
	fill = (fill ? 0XFF : 0);
	// shift left by s/8 bytes
	{
		int i;
		int j = n - 1;
		if (n > m){
			i = m - 1;
		}
		else{
			i = n - s / 8 - 1;
		}
		
		for (; j >= m + s/8; j--){
			z[j] = 0;
		}
		for (; i >= 0; i--, j--){
			z[j] = x[i];
		}
		for (; j >= 0; j--){
			z[j] = fill;
		}
	}
	
	s % = 8;
	if (s > 0){
		// shift z left by s bits
		XP_product(n, z, z, 1 << s);
		z[0] |= fill >> (8 - s);
	}
}


void XP_rshift(int n, T z, int m, T x, int s, int fill){
	fill = (fill ? 0XFF : 0);
	// shift right by s/8 bytes
	{
		int i;
		int j = 0;
		
		for (i = s/8; i < m && j < n; i++, j++){
			z[j] = x[i];
		}
		for (; j < n; j++){
			z[j] = fill;
		}
	}
	
	s % = 8;
	if (s > 0){
		// shift z right by s bits
		XP_quotient(n, z, z, 1 << s);
		z[n - 1] |= fill << (8 - s);
	}
}


int XP_fromstr(int n, T z, const char *str, int base, char **end){
	const char *p = str;
	
	assert(p);
	assert(base >= 2 && base <= 36);
	
	// skip white space
	while (*p && isspace(*p)){
		p++;
	}
	
	// *p  is a digit in base
	if (isBaseDigit(*p){
		int carry;
		// *p is digit in base
		for (; isBaseDigit(*p); p++){
			carry = XP_product(n, z, z, base);
			if (carry){
				break;
			}
			XP_sum(n, z, z, map[*p - '0']);	// map[*p - '0'] 字符映射为数字
		}
		if (end){
			*end = (char *)p;
		}
	}
	else{
		if (end){
			*end = (char *)str;
		}
		
		return 0;
	}
}


char *XP_tostr(char *str, int size, int base, int n, T x){
	int i = 0;
	
	assert(str);
	assert(2 <= base && base <= 36);
	
	do{
		int r = XP_quotient(n, x, x, base);
		assert(i < base);
		str[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[r];	// =p[i]
		while (n > 1 && x[n - 1] == 0){
			n--;
		}
	} while (n > 1 || x[0] != 0);
	
	assert(i < size);
	str[i] = '\0';
	// reverse str 
	{
		int j;
		for (j = 0; j < --i; j++){
			char c = str[i];
			str[j] = str[i];
			str[i] = c;
		}
	}
	
	return str;
}