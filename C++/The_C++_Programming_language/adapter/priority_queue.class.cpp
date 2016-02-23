/*
	优先级队列 
	向量实现的适配器
	
	cmp函数谓词，定义优先级
*/

template<class T, class C = vector<T>, class Cmp = less<typename C::value_type> >
class std::priority_queue
{
	protected :
		C c;		// 容器存放元素
		Cmp cmp;	// 逻辑谓词，定义优先级
	
	public :
		typedef typename C::value_type;
		typedef typename C::size_type size_type;
		typedef C container_type;
		
		explicit priority_queue(const Cmp& a1 = Cmp(), const C& a2 = C()) : c(a2), cmp(a1) 
		{ 
			make_heap(c.begin(), c.end(), cmp); 
		}
		
		template <class In>
			priority_queue(In first, In last, const Cmp& x = Cmp(), const C& y = C());
			
		bool empty() const
		{
			return c.empty();
		}
		size_type size() const
		{
			return c.size();
		}
		
		const value_type& top() const
		{
			return c.front();	// ?
		}
		
		void push(const value_type&);
		void pop();
};

// test
typedef priority_queue<string, vector<string>, string_cmp> myqueue;