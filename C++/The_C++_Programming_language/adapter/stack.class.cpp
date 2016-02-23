/*
	堆栈的实现	--	适配器
	双端队列实现的
	
	非常简单，借助基本容易，直接当做其成员变量即可，用于存储数据
	第二步，即重新定义界面！
*/
template<typename T, typename C = deque<T> > 
class std::stack
{
	protected :
		C c;
	public :
		typedef typename C::value_type value_type;
		typedef typename C::size_type size_type;
		typedef C container_type;
		
		explicit stack(const C& a = C()) : c(a) {}
		
		bool empty() const
		{
			return c.empty();
		}
		
		size_type size() const { return c.size(); }
		
		value_type top() const { return c.back(); }
		const value_type top() const { return c.back(); }
		
		void push(const value_type& x) { c.push_back(x); }
		void pop() { c.pop_back(); }
};
