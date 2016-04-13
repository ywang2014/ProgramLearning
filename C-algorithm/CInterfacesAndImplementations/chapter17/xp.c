#include <ctype.h>
#include <string.h>
#include "assert.h"
#include "xp.h"

#define T XP_T
#define BASE (1 << 8)

// data


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
			
			q[k] = qk;
			// rem <-- rem - dq*b^k 
			
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