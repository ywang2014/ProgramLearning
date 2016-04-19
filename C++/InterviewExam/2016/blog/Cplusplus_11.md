## C++11的新特性

1.auto 声明变量，自动获取类型
	
	std::vector<int> vec = { 1, 2, 3 };
	auto it = vec.begin();

2.decltype 自动类型推断机制，根据函数参数，推断返回值，故返回值在最后

	std::list<int>::iterator p = list.begin();
	decltype(p) q = p;	// auto过程相反

3.for循环，自带范围的，for (int x : arr);

	map<string, int> m{ {"name", 1}, {"number", 2}, {"grade", 3} };
	for (auto p : m){
		isSuitable(p.first);
	}

4.lambda 表达式，创建匿名函数对象。

	[函数对象参数]（操作符重载函数参数）->返回值类型{ 函数体 }
		vector<int> iv{5, 4, 3, 2, 1};  
		int a = 2, b = 1;  
		
		for_each(iv.begin(), iv.end(), [b](int &x){cout<<(x + b)<<endl;}); // (1)  
		for_each(iv.begin(), iv.end(), [=](int &x){x *= (a + b);});     // (2)  
		for_each(iv.begin(), iv.end(), [=](int &x)->int{return x * (a + b);});// (3) 
		
		[]内的参数指的是Lambda表达式可以取得的全局变量,(1)函数中的b就是指函数可以得到在Lambda表达式外的全局变量
		如果在[]中传入=的话，即是可以取得所有的外部变量，如（2）和（3）Lambda表达式
		()内的参数是每次调用函数时传入的参数
		->后加上的是Lambda表达式返回值的类型，如（3）中返回了一个int类型的变量
		

5.nullptr 空指针，NULL(0)具有二义性

6.更加优雅的初始化方法
	
	在引入C++11之前，只有数组能使用初始化列表，c++11所有的都可以使用初始化列表
		int arr[3]{1, 2, 3};  
		vector<int> iv{1, 2, 3};  
		map<int, string>{{1, "a"}, {2, "b"}};  
		string str{"Hello World"}; 
		
		
7.右值引用 && (Move语义)

	MyClass::MyClass(const MyClass &obj);				// 拷贝构造函数
	MyClass &MyClass::operator=(const MyClass &obj);	// 拷贝赋值函数
	MyClass::MyClass(MyClass &&obj);					// move构造函数
	MyClass &MyClass::operator=(MyClass &&obj);			// move赋值函数
	
	左值优先绑定左值引用，右值优先绑定右值引用。
	不能将左值传递给一个右值引用
	
8.auto_ptr智能指针被舍弃，shared_ptr unique_ptr weak_ptr

	unique_ptr: 如果内存资源的所有权不需要共享（它没有拷贝构造函数），但是它可以转让给另一个unique_ptr（存在move构造函数）
	shared_ptr: 如果内存资源需要共享
	weak_ptr: 持有被shared_ptr所管理对象的引用，但是不会改变引用计数值
		被用来打破依赖循环
		在一个tree结构中，父节点通过一个共享所有权的引用(chared_ptr)引用子节点，同时子节点又必须持有父节点的引用。
		如果这第二个引用也共享所有权，就会导致一个循环，最终两个节点内存都无法释放
		
9.非成员begin()和end()

	int arr[] = {1,2,3};
	std::for_each(std::begin(arr), std::end(arr), [](int n) {std::cout << n << std::endl;});

10.static_assert和 type traits

	static_assert提供一个编译时的断言检查。如果断言为真，什么也不会发生。如果断言为假，编译器会打印一个特殊的错误信息。
	
11.Strongly-typed enums 强类型枚举

12.Override和final