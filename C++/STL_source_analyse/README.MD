# STL源代码剖析-侯捷
The Annotated STL Source(using SGI STL)

天下大事 必作于细

向专家学习类型技术、内存管理、算法、数据结构、STL各类组件之高阶实现技巧
	
第1章 STL概论与版本简介
	
	STL六大组件：
		容器：vector list deque set map 	STL容器是一种class template
		算法：sort search copy erase		STL算法是一种function template
		迭代器(iterator)：“泛型指针”，容器和算法间的桥梁。迭代器主要是重载了operator*(->/++/--)等指针相关操作的class template
		仿函数(functors)：作为算法的某种策略	函数对象是一种重载了operator()的class 或class template
		适配器(adapters)：用来修饰容器、函数对象、迭代器接口的东西，修改接口，提供其他功能特性，如 stack queue
		分配器(allocators)：负责空间分配和管理	分配器是一个实现了动态空间分配、管理、释放的class template 
	Container通过Allocator取得数据存储空间，Algorithm通过Iterator存取Container内容，Functor协助Algorithm完成不同策略变化，
	Adapter修饰或套接Functor
	
	友元模板：friend bool operator== <> (const stack&, const stack&);
	临时对象：算法中喜欢使用临时对象，for_each (v.begin(), v.end(), print<int>()); “类型名(初始值)”
	静态整形(int char long...)常量数据成员，可以在class内，直接给予初值 (p70)
	
	


###### Date
开始时间：2016-05-19

结束时间：2016-

#### 阅读感想