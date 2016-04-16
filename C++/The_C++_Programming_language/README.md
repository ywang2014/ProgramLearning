#The C++ Programming Language(Special Edition) -- Bjarne Stroustrup 裘宗燕译

刚刚看完C专家一书，收获有哪些，具体也说不上，以前知道的内容，自然看得很轻松，当做复习巩固一遍，有些新颖的内容，看得很晕乎，感觉太深了。我的看书
陋习，不喜欢看第二遍，所以直接开始看这本书了。

这本书比较厚，900多页，内容比较多，看得最吃力的一本书，很多内容很新，以前没有见过的说法，一天想看完20页，都感觉很吃力，我一般是上午坚持学习C/C++，
其他时间学习其他的东西，以C/C++为主，作为找工作、职业发展的重点，学习Java、PHP等作为其他兴趣，然后边做项目，现在都必须加班，下午还得再看1个小时左右，
否则很可能上午只能看几页，10页。其实上午我一般9点左右到实验室，11点左右吃饭，简单的内容，其他书好像很容易看20页-30页左右，这本书，内容很苦涩，看得很难理解，
好像有的翻译语句都不通顺，不知道我理解能力太差，还真的是读不通。希望我可以坚持看完，今年回家过年前，多看一点。**Date: 2016-01-05**

开始看书时间，应该是2015-12-27左右，就当做元旦开始的吧，期待我看完这书的那一天，然后看看共用了多少时间，并且来完成这篇读书笔记，写写学习总结和心得。


第11章，静态对象缓冲区，很不错的技术

第13章，模板中的高级技术，从基类派生出模板类，或者模板类派生；全部(部分)专门化，抑制代码膨胀，实现共享；模板默认参数
	
	抽象类：运行时多态，编译时不知道对象的类型，具有类层次结构
	模板：编译时多态，不具有层次结构性关系，效率更高，容易实现inline。

第14章，异常处理中的技巧，保证资源申请和释放，将资源指针封装在类中，利用类的构造函数、析构函数，创建和释放，“资源申请即初始化”技术。
	
	auto_ptr 所有权语义(ownership semantics)	破坏性复制语义(distructive copy semantics)
	
第15章，这章讲类层次结构，实在是感觉很复杂，逻辑很绕的。多重继承，虚基类的，运行时类型信息

	用户界面系统的开发，技巧实在是灵巧。界面与实现隔离，并隐藏实现细节
	dynamic_cast限制在多态类型上，虚函数表中，存放有一个指向类型信息的指针
	dynamic_cast在指针转换时，表示提问，失败返回0；在引用的转换时，表示断言，失败抛出bad_cast异常。
	dynamic_cast 在基类指针确实指向派生类对象的时候，就可以将此基类指针强制转换成该派生类指针，否则准换失败。
	
	任何时候，都不要尝试把将基类指针转换为派生类指针，未定义！ 
	15.5.1 反变：指向基类成员的指针可以安全的赋值给指向派生类的成员的指针	--> 允许指向派生类的指针给指向基类的指针赋值<-->多态
	
	虚析构函数	多态的运用
	
第16章，主要讲了标准库组织和容器，内容很多，技巧很强，很多都是看着好像明白，实际应该是完全不会的

	标准库的设计，容器的设计，技巧非常强，从灵活、方便，但效率不高的基类抽象派生到兼容灵活、方便、效率的统一界面的模板方式使用，
	一个模型比一个模型漂亮。
	
	16章的主体是讲解了vector模板，既帮助学习运用vector，又可以学习标准库、容器的开发。看本书之后，才知道自己对于vector的无知，平常使用很少，
	一般只会使用数组，C风格的影响，现在慢慢理解了模板，类型参数这类看似神奇的东西。
	
	vector里面的内容非常丰富，第一个让我开眼界的就是，类型当做类成员变量，第一次看见，神奇。使用技巧：typename C::value_type 
	typename可以告诉编译器，该成员属于类型，不是普通成员。
	
	再一次理解的迭代器，iterator，一直感觉很神奇的东西，其实也就是一个类，或者一个类型。使用不用管，直接 "vec.begin()+i"即可，
	*it ++it也是可行的(标准迭代器)，当做指针使用，实际使用不要用指针即可。算法的访问、操作，多是依靠迭代器的。sort()
	然后知道了，reverse_iterator 与iterator可能不同，但是可以转换：base()函数即可实现
	
	vector可以堆栈操作：push_back()	pop_back() back()
	表操作：insert()	erase()
	容量：size()	resize()（realloc()）	capacity()	
		reserve() 预留空间，既可以提高效率，还能保证内存位置不变，即可保证避免迭代器非法，产生未定义行为，高技巧！
		
	vector的理解更加深刻了一些，[] 和 at() 的区别，一个是高效率不安全的，一个是有越界检查安全的。
		
	vector<bool> 专门具体化，需要考虑二进制位模拟寻址操作
	
	vector是非常强大的数组，只要掌握，使用超级方便。直接当做普通序列，数组；直接模拟stack, 使用三个相关函数即可；直接模拟string vector<char>
	
	vector的灵活运用技巧，关键就是看 typename T, 可以放入任何类型。放入vector就是数组的数组(二维数组)，放入point，就是点对。link就是链表向量。
	放入基类的指针，即可实现多态，非同质。

第17章 标准容器，主要介绍了各种容器的实现，包括有序列，适配器，关联容器，拟容器，自定义容器等，不仅有详细的关于实现的理论、技巧讲解，还有具体的
源代码讲解，分析。

	标准容器：序列和关联容器	标准容器所有可能之处，具有逻辑互换性，都可以使用，只是效率，特定操作不同而已
	序列：vector、list、deque
	适配器：stack、queue、priority_queue	适配器是通过序列定义适当的界面实现的。
	关联容器：set、map、multiset、multimap	关联数组，主要特征是，可以使用关键码作为下标，访问映射值。	pair<K, V>键值对操作
	拟容器：数组、string、valarray、bitset	非标准容器，实现不同，使用有些区别。
	hash_map的实现,hash_**		用户实现自己添加自定义容器，封装统一界面接口。
	
	关键操作：
		表操作(insert、erase)，堆栈操作(push、pop、back)
		排序、归并、查找、粘接(splice)、unique。。。
		
	内部数组的封装，实现统一界面
	operator[]() 和find() 的不同，对于关联容器，[]会插入不存在的关键码，改变容器，不能const
	
实际编程，根据需要选择合适的容器，首先vector，不要使用数组了。C风格的字符串，一定要提供适当的比较准则，strcmp()等。
map是有序的，hash_map是无序的。hash_map查找效率更高。
		
第18章 算法和函数对象
	
	标准算法在名称空间std中，声明在<algorithm>里，标准函数对象在名称空间std里，声明在<functional>里。
	
	Iseq封装迭代器，将输入序列变成明显可见的，简单、安全。
	
	函数对象	拟函数对象	应用运算符	谓词
	标准库提供了很多函数对象、谓词
	
	函数对象基类：unary_function<T, C>	binary_function<T, K, C>
	
	约束器
	成员函数适配器
	函数指针适配器
	否定器
	
	排序序列：sort、二分查找、归并、划分、集合操作：includes()、set_difference()、set_symmetric_difference()
	
	堆：heap	<--> priority_queue
		push_heap()、pop_heap()、sort_heap()	
	
	最大、最小	max_element()	min_element()
	字典序：lexicographical_compare()
	
	排列 next_permutation()		prev_permutation()
	
	兼容性：
		C语言中：qsort()	bsearch()
		C++中：  sort()		search()
		
	std::mem_fun和std::mem_fun_ref所实现的是相同的功能
		mem_fun()用于处理容器对象指针
		mem_fun_ref()用于处理容器对象实体
		
总结：标准库提供了很多算法，通用性、完整性、鲁棒性非常好，多使用算法，少使用循环，少造轮子！
find()	for_each()	tranform()	search()	sort()	unique()	remove()	lower_bound()...

第19章 迭代器和分配器 
	
	迭代器是链接容器和算法的纽带，提供了一个数据访问的标准模型
	分配器被用于将容器的实现隔离在对存储访问的细节之外，提供了一种映射，将低级数据结构模型映射到高级对象模型。
	
	iterator
		分类：Out In For Binary Rand
		操作：++ *p(读、写) --  +  == !=  
	
	iterator_traits
	
	inserter /back_inserter	(避免容器的溢出)
	
	迭代器操作，尽量使用前缀++，后缀++会产生临时变量，影响效率
	
	allocator
		new/delete
		malloc/free
	
	未初始化内存分配：
		uninitialized_copy()
		uninitialized_fill()
		uninitialized_fill_n()
		get_temporary_buffer() // 只分配不构造		return_temporary_buffer() // 只释放不销毁  (成对使用)
		get_temporary_buffer属于低级机制，专门用于快速分配，优化使用的，不能代替new()，allocator::allocate()
		
		Obj a = new Obj()	/	Obj *b = new Obj	a将被初始化为0，b不会被初始化，垃圾值
		
	raw_storage_iterator	做的是初始化，而不是赋值
	
第20章 串

	这一章，完整讲解了basic_string类的接口实现，接口非常多，但是分类很清晰，明确，并讲解了实现所需技巧和注意事项。
	typedef basic_string<char> string	basic_string<>是一个模板类，类似于vector一样的容器，接口和vector相似，
	string是basic_string模板的一个实例化。
	basic_string模板类的接口非常多，包含各种常规的操作。
	
	C标准库中，关于C风格字符串的操作函数，字符操作函数等
	
	atoi() atol() atof()		strtol() strtod()	仅错误处理方式不同，其他一样。
	long atol(const cahr *p);		long strtol(const char *p, char **end, int b);
	atol(s) = strtol(s, 0, 10)
	
	at() operator[] 区别：at()更加安全，有返回越界检查，[]和迭代器都没有检查。[]速度更快，效率高
	
	C++编程，尽量多用string，少用c风格字符串(多使用容器，标准库算法，少些循环，数组等一样) 【安全、效率】
	
第21章 流

	<iosfwd> 流I/O类和模板声明，标准typedef等，部分I/O头文件
	ios_base <-- bisic_ios <--(virtual public) basic_ostream(basic_istream)
	
	输出：从各种类型，到字符序列的转换结果
	输入：从字符序列，获取各种类型格式的值
		tie() 流联结，cin.tie(&cout)	自动刷新 cout.flush()
		sentry类：通过一个类，采用构造函数和析构函数，提供公共的前缀和后缀代码
	格式化：输出布局的需求
		flags()		用标志位的方式控制流状态
		操控符
		
	流：文件(istream, ostream, file)
		ostream istream iostream 
		ofstream ifstream fstream
		ostringstream istringstream stringstream
		ostrstream istrstream
	缓冲区：提高I/O效率
	locale：文化差异
	C语言I/O：scanf() printf()