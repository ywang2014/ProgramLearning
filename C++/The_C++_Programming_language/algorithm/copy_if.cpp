/**
	标准库中没有copy_if()算法
	
	自定义
		In 输入迭代器
		Out 输出迭代器
		Pred 逻辑谓词，即判断标准，函数对象
*/
template<class In, class Out, class Pred>
Out copy_if(In first, In last, Out res, Pred p)
{
	while (first != last)
	{
		if (p(*first))
		{
			*res++ = *first;
		}
		
		first++;
	}
	
	return res;
}