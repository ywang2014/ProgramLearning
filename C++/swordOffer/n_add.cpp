/**
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
	
	1. 利用构造函数 cons(int n){ sum += n; }	// 构造一个数组即可！
	2. 利用虚函数
	3. 利用函数指针，其实等价于虚函数
	4. && 短路

*/



class Solution {
public:
    int sum = 0;	// 类成员的特性，使用静态，需要初始化！
    int Sum_Solution(int n) {
         n && Sum_Solution(n-1);
        return sum += n;
    }
};

class Solution2 {
public:
    int Sum_Solution(int n) 
	{
        int sum = 0;
		fun(n, sum);
        return sum;
    }
    
	int fun(int n, int& sum)
	{
		n && fun(n-1, sum);	// 最关键的，&& 短路
		return sum += n;
	}
};


typedef int (*fun)(int);  
  
int solution_f1(int i)  
{  
    return 0;  
}  
  
int solution_f2(int i)  
{  
    fun f[2]={solution_f1, solution_f2};  
    return i+f[!!i](i-1);  
}  