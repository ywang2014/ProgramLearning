/**
	C++标准库，特殊函数
	
	如果需要操作容器对象自身的成员方法时，需要使用mem_fun()函数
	
	std::mem_fun和std::mem_fun_ref所实现的是相同的功能
	mem_fun()		用于处理容器对象指针
	mem_fun_ref()	用于处理容器对象实体
*/

class TestClass
{
	public :
		void operatorA(void)
		{
			// Todo
			std::cout << "Hello \n";
		}
};

std::list<TestClass> data;

// 普通循环操作
typedef std::list<TestClass>::iterator IT;
for (IT it = data.begin(); it != data.end(); it++)
{
	(*it).operatorA();
}

/** 对于容器操作，尽量不使用循环，多使用算法函数 */
// for_each()等价操作
for_each(data.begin(), data.end(), std::mem_fun_ref(&TestClass::operatorA));


std::vector<TestClass* > data;
for_each(data.begin(), data.end(), std::mem_fun(&TestClass::operatorA));