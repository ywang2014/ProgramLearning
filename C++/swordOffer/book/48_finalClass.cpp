/**
	不能被继承的类
	
	用C++设计一个不能被继承的类。
*/

class SealedClass
{
	public:
		static SealedClass* getInstance()
		{
			return new SealedClass();
		}
		
		static void deleteInstance(SealedClass* instance)
		{
			delete instance;
		}
	
	private:
		SealedClass() {}
		~SealedClass() {}
};


// 版本二：虚拟继承
template<typename T> 
class MakeSealed
{
	friend T;
	
	private:
		MakeSealed(){}
		~MakeSealed(){}
};

class SealedClass: virtual public MakeSealed<SealedClass>
{
	public :
		SealedClass(){}
		~SealedClass(){}
};