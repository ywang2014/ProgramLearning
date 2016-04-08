/**
	快速求整数n中，有多少个1
*/
#include <iostream>

int numsOf1(long long n){
	// 4bits 数中1的个数
	static countOf1[] = { 0, 1, 1, 2, 1, 2, 2, 3, 
		1, 2, 2, 3, 3, 2, 3, 3, 4, 1, };
		
	char *pCh  = (char *)(&n);
	int counts = 0;
	for (int i = 0; i < 8; i++)
	{
		counts += countsOf1[*pCh & 0xF] + countOf1[*pCh >> 4];
	}
	
	return counts;
}

int numsOf1(long long n){
	int counts = 0;
	
	while (n){
		counts++;
		n &= (n - 1);
	}
	
	return counts;
}