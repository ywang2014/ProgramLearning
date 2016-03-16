/**
	包含min函数的栈
	
	定义栈的数据结构，请在该类型中，实现一个能够得到栈最小元素的min函数。在栈中，调用min、push及
	pop的时间复杂度都是O(1)。
	
	添加一个辅助栈，专门用于存储最小值。
*/
template<typename T>
class StackWithMin
{
	private :
		const int M_size = 100;
		
		int index = -1;
		T data[M_size];
		T minValue[M_size];
	
	public :
		void push(const T& value);
		void pop();
		const T& top() const;
		const T& min() const;
		
		bool empty() const
		{
			return index == -1;
		}
		
		bool full() const
		{
			return (index == (M_size - 1));
		}
};

template<typename T> void StackWithMin<T>::push(const T& value)
{
	if (empty())
	{
		data[++index] = value;
		minValue[index] = value;
	}
	else if (! full())
	{
		data[++index] = value;
		if (minValue[index - 1] > value)
		{
			minValue[index] = value;
		}
		else
		{
			minValue[index] = minValue[index-1];
		}
	}
	else 
	{
		throw new exception("stactk overflow!");
	}
}

template<typename T> void StackWithMin<T>::pop()
{
	if (! empty())
	{
		index--;
	}
	else 
	{
		throw new exception("statck underflow!");
	}
}

template<typename T> const T& StackWithMin<T>::top() const
{
	return data[index];
}

template<typename T> const T& StackwithMin<T>::min() const
{
	return minValue[index];
}

/*********************** 参考代码 **/
// 两个栈，实现该栈
template<class T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	
	if (m_min.size() == || value < m_min.top())
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

template<class T> void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0 );
	
	m_data.pop();
	m_min.pop();
}

template<class T> const T& StackWithMin<T>::min() const 
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	
	return m_min.top();
}


