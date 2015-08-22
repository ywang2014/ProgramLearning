# C++
## c++模板
	1.函数模板
	格式：template <typename T, typename B...>
	      void fn(T a, B b)
	      {
	      	...
	      }

	调用时：
		int a;
		float b;
		fn(a, b); //实参推演，不能使用fn(int, float)

	2.类模板
	格式：template<typename T1, typename T2...> class className{}
		eg: className<int, float> a or ::fn(){}
	      template<typename T>
	      class A
	      {
	      	public:
			T a;
			T b;
			T fn(T c, T d);
	      }
	      A<int> object; //不能使用 A(2) object
	
