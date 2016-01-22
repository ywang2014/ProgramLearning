/*
	auto_ptr模板
	在<memory>里声明的
	
	auto_ptr的破坏性复制语义，意味着它不满足标准容器、标准算法
*/

template <typename T> class std::auto_ptr
{
	template <class Y> struct auto_ptr_ref	// 协助类，实现破坏性复制语义
	{
		Y* rptr;
		auto_ptr_ref(Y* a) : rptr(a) {}
	};	
	
	T* ptr;
	
	public:
		typedef T element_t;
		// 构造函数，显示声明，禁止隐式转换，默认参数
		explicit auto_ptr(T* p = 0) throw()	// throw说明“不抛出异常”
		{
			ptr = p;
		}
		~auto_ptr() throw()
		{
			delete ptr;
		}
		
		// 复制构造函数、赋值都用非const参数
		auto_ptr(auto_ptr& a) throw()	// 复制构造，然后a.ptr = 0, 所以不能使用const auto_ptr&
		{
			ptr = a.release();
		}
		template<class Y> auto_ptr(auto_ptr<Y>& a) throw()
		{
			ptr = a.release();
		}
		
		auto_ptr& operator=(auto_ptr& a) throw()
		{
			reset(a.release());
			return *this;
		}
		
		template<class Y> auto_ptr& operator=(auto_ptr<Y>& a) throw();
		
		T& operator*() const throw()	// 解除引用，返回指针对应的对象
		{
			return *ptr;
		}
		
		T* operator->() const throw()	// 间接成员运算符
		{
			return ptr;
		}
		
		T* get() const throw()	// 提取指针
		{
			return ptr;
		}
		
		// release()释放本对象拥有的指针的引用，并将其传出来
		T* release() throw()	// 放弃指针所有权
		{
			T* t = ptr;
			ptr = 0;
			return t;
		}
		
		// reset()会将本对象拥有的指针引用重置为另一个指针，原指针对应的内存销毁
		void reset(T* p = 0) throw()
		{
			if (p != ptr)
			{
				delete ptr;
				ptr = p;
			}
		}
		
		auto_ptr(auto_ptr_ref<T> a) throw()	// 从auto_ptr_ref复制
		{
			ptr = a.rptr;
		}
		
		// 强制类型转换函数
		template<class Y> operator auto_ptr_ref<Y>() throw();	// 类型转换重载
		template<class Y> operator auto_ptr<Y>() throw()		// 从auto_ptr的破坏性复制
		{
			// 用指针重新生成另外一个对象，自己解除对指针的引用
			return auto_ptr<Y>(release());
		}
}