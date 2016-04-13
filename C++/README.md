# C++
[gcc历史版本源代码](ftp://ftp.gnu.org/pub/gnu/gcc/)

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
		  
##内敛
	1.inline 函数 
	实现高效性
	
##宏	(编译概念，预处理完成)
	1.宏常量	简单字符替换
	2.宏函数
	
编程原则，尽量不使用宏，使用模板的泛型和内敛的高效替代宏实现

	宏函数：
	#define SUM(a, b) ((a) + (b))
	
	模板+内敛：
	template<typename T>
	inline T sum(const T &a, const T &b){
		return (a + b);
	}
	
#### 必须使用宏的地方
	
	1.字符连接
		
		字符串化操作符#	
		#parameter	--> "parameter"
		能够字符串化操作的必须是宏参数，不是随随便便的某个子串（token）都行的
			
			#define STRING(str) #str // "str"  (必须是宏函数中的参数，才可以字符串化)
		
		宏定义中的连接符##
		连接符##用来将两个token连接为一个token，但它不可以位于第一个token之前or最后一个token之后。
		注意这里连接的对象只要是token就行，而不一定是宏参数,但是##又必须位于宏定义中才有效，因其为编译期概念。
		
			#define LINK(a, b) __##a##__##b##__	// __a__b__
		
	
	2.linux内核的链表实现 list_entry
		
		#define list_entry(ptr, type, member) ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))	// 0(NULL)
		使用list_entry()宏，在linux链表中访问链表数据
		
		原理：指针ptr指向结构体type中的成员member，通过指针ptr，返回结构体type起始地址
			(unsigned long)(&((type *)0)->member) 把0地址转化为type结构的指针，然后获取结构中member成员指针，
			并将其强制转换为unsigned long 类型
			
	**类成员函数指针相关知识点**
	如果类成员函数，没有访问类的成员数据，可以使用NULL指针获取其成员函数指针 ((type *)NULL)->fun()
		否则有问题，NULL指针，不能访问其成员数据 (*this指针)
	对象访问成员函数指针 obj.(*fun)()
	类名访问成员函数指针 &OBJ::fun	(普通函数指针不同，必须取地址)
	
	
	3.程序中在执行某些操作时可能会失败，此时要打印出失败的代码位置，只能使用宏实现。 
		
		#define SHOW_CODE_LOCATION() cout << __FILE__ << ':' << __LINE__ << endl
		// 调用
		if (error){
			SHOW_CODE_LOCATION();
		}
	