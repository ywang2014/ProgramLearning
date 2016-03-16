/**
	栈的压入、弹出序列
	
	输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不等。
	
	例如：
		序列：1 2 3 4 5是某栈的压栈序列
		序列：4 5 3 2 1是该压栈序列对应的一个弹栈序列，但是 4 3 5 1 2就不可能是该压栈序列的弹出序列。
*/

bool isLegalSequence(const int* pushSequence, const int* popSequence, unsigned int length)
{
	stack<int> s;
	
	unsigned int pushIndex = 0;
	unsigned int popIndex = 0;
	
	s.push(pushSequence[pushIndex]);
	
	while (popIndex < length)
	{
		// while (s.top() != popSequence[popIndex] && pushIndex < length)
		// {
		//	s.push(pushSequence[pushIndex++]);	// 这样不行，pushIndex < length 在最后一个元素入栈后，就恒成立！
			// s.push(pushSequence[++pushIndex]);
		// }
		
		// 上面修改过后，这样逻辑就有问题，此时if成立，则栈已经溢出
		// if (pushIndex == length)
		// {
			// return false;
		// }
		// else // 找到了出栈的值
		// {
			// s.pop();
			// popIndex++;
		// }
		
		while (s.top() != popSequence[popIndex] && pushIndex < length)
		{
			++pushIndex;
			if (pushIndex == length)
			{
				return false;
			}
			
			s.push(pushSequence[pushIndex]);
		}
		
		s.pop();
		popIndex++;
	}
}


// 第一种逻辑的实现
bool isLegalSequence(const int* pushSequence, const int* popSequence, unsigned int length)
{
	stack<int> s;
	
	unsigned int pushIndex = 0;
	unsigned int popIndex = 0;
	
	s.push(pushSequence[pushIndex++]);
	
	while (popIndex < length)
	{
		while (s.top() != popSequence[popIndex] && pushIndex < length)
		{
			s.push(pushSequence[pushIndex++]);	
		}
		
		if (s.top() != popSequence[popIndex])	// 说明没有找到
		{
			return false;
		}
		else // 找到了出栈的值
		{
			s.pop();
			popIndex++;
		}
	}
}


/******************** 参考代码  **/
bool isPopOrder(const int* push, cosnt int* pop, int length)
{
	bool possible = false;
	
	if (push != NULL && pop != NULL && length > 0)
	{
		const int* nextPush = push;
		const int* nextPop = pop;
		
		std::stack<int> stackData;
		
		while (nextPop - pop < length)
		{
			while (stackData.empty() || stackData.top != *nextPop)
			{
				if (nextPush - push == length)
				{
					break;
				}
				
				stackData.push(*nextPush);
				
				nextPush++;
			}
			
			if (stackData.top() != nextPop)
			{
				break;
			}
			
			stackData.pop();
			nextPop++;
		}
		
		if (stackData.empty() && nextPop - pop == length)
		{
			possible = true;
		}
	}
	
	return possible;
}
	