/**
	STL vector
	
	用于存放元素的数据成员，没有看见！
*/

template <class T, class A = allocator<T> > 
class std::vector
{
	public :
		// 类型
		typedef T value_type;		// 元素类型
		typedef A allocator_type;	// 存储管理器类型
		typedef typename A::size_type size_type;
		typedef typename A::difference_type difference_type;
		
		typedef implementation_dependent1 iterator;			// T*
		typedef implementation_dependent2 const_iterator;	// cosnt T*
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		
		typedef typename A::pointer pointer;		// 元素指针
		typedef typename A::const_pointer const_pointer;
		typedef typename A::reference reference;	// 元素引用
		typedef typename A::const_reference const_reference;
		
		
		// 迭代器
		iterator begin();
		const_iterator begin() const;
		iterator end();					// 指向超尾元素
		const_iterator end() const;
		
		reverse_iterator rbegin();		// 指向反向序列的首元素
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		
		
		// 元素访问
		reference operator[](size_type n);		// 不加检查的访问
		const_reference operator[](size_type n) const;
		
		reference at(size_type n);
		const_reference at(size_type n) const;
		
		
		// 构造函数
		explicit vector(const A& = A());
		explicit vector(size_type n, const T& val = T(), const A& = A());	// n个val的副本
		template <class In>								// In必须是输入迭代器
			vector(In first, In last, const A& = A());	// 由[first, last]复制
		vector(const vector& x);
		
		~vector();
		
		vector& operator=(const vector& x);
		
		template <class In>
			void assign(In first, In last);
		void assign(size_type n, const T& val);
		
		
		// 堆栈操作
		void push_back(const T& x);
		void pop_back();
		const T& back();
		
		
		// 表操作
		iterator insert(iterator pos, const T& x);		// 在pos前加入x
		void insert(iterator pos, size_type n, const T& x);		// 在pos前加入n个x
		template <class In> 
			void insert(iterator pos, In first, In last);
		
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void clear();
		
		
		// 容量操作
		size_type size() const;
		bool empty() const { return size() == 0;}
		size_type max_size() const;
		void resize(size_type sz, T val = T());
		
		size_type capacity() const;
		void reserve(size_type n);
		
		
		//
		void swap(vector& );
		allocator_type get_allocator() const;
};