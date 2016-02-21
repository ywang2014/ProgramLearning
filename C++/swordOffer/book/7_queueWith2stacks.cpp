/*
	用两个栈实现队列
	用两个栈实现队列。队列的声明如下，请实现他的两个函数appendTail deleteHead, 分别完成在队列的尾部插入节点，队列头删除节点
*/

template <typename T>
class CQueue
{
	public:
		CQueue(void);
		~CQueue(void);
		
		void appendTail(const T& node);
		T deleteHead();
		
	private:
		stack<T> stack1;
		stact<T> stack2;
};

template <class T> 
void CQueue::appendTail(const T& node)
{
	if (!stack1.full())
	{
		stack1.push(node);
	}
	else if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.pop());
		}
		
		stack1.push(node);
	}
	else
	{
		throw std::exception("invalid operator!");
	}
}

template <class T>
T CQueue::deleteHead()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.pop());
		}
	}
	
	if (stack2.empty())
	{
		throw std::exception("no data!");
	}
	return stack2.pop();
}

/************************************* 参考答案 *********************************************/
template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() >= 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	
	if (stack2.size() == 0)
	{
		throw new exception("queue is empty");
	}
	
	T head = stack2.top();
	stack2.pop();
	
	return head;
}



