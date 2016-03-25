/**
	求 1+2+3+...+n 
	
	求 1+2+3+...+n，要求不能使用乘除法，for while if else switch case 等关键字和条件判断语句。
*/
void add(int n, int& sum)
{
	sum += n;
	n && add(n-1, sum);
}


/************ 参考代码 **********/

// 版本一：构造函数
/*
	非静态可以直接访问静态
	静态不可以直接访问非静态
	
因为静态函数可以直接通过 类::函数 中方式调用，不用通过对象来调用函数，而非静态函数必须通过对象来调用，这里面还涉及到实例化对象时候的内存分配。
*/
class Add
{
	public:
		Add()
		{
			++n;
			sum += n;
		}
		
		static int sum()
		{
			return sum;
		}
		
		static void reset(int n = 0, int sum = 0)
		{
			this->n = n;
			this->sum = sum;
		}
	
	
	private:
		static int n;
		static int sum;
};

int Add::n = 0;
int Add::sum = 0;

int getAddSum(unsigned int n)
{
	Add::reset(0, 0);
	
	Add* nAddObjects = new Add[n];
	int sumResult = Add::sum();
	
	delete[] nAddObjects;
	nAddObjects = NULL;
	
	return sumResult;
}


// 版本二：利用虚函数求解
class A;
A* Array[2];

class A
{
	public :
		virtual unsigned int sum(unsigned int n)
		{
			return 0;
		}
};

class B: public A
{
	public:
		virtual unsigned int sum(unsigned int n)
		{
			return Array[!!n]->sum(n-1) + n;
		}
};

int getAddSum(int n)
{
	A a;
	B b;
	
	Array[0] = &a;
	Array[1] = &b;
	
	int value = Array[1]->sum(n);
	
	return value;
}


//版本三：利用函数指针求解
typedef unsigned int (*fun)(unsigned int );

unsigned int teminator(unsigned int n)
{
	return 0;
}

unsigned int getAddSum(unsigned int n)
{
	static fun f[2] = {teminator, getAddSum};
	
	return n + f[!!n](n - 1);
}


// 版本四：利用模板类型求解
template <unsigned int n> 
struct sum_solution4
{
	enum Value{ N = sum_solution4<n - 1>::N + n };
};

// 具体化 n = 1
template <> struct sum_solution4<1>
{
	enum Value { N = 1 };
};

