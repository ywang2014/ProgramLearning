/**
	Algorithm sum
	
	typename C::**	获得成员类型，必须使用typename
*/

template <class C> 
typename C::value_type sum(const C& con)
{
	typename C::value_type result = 0;				
	typename C::const_iterator it = con.begin();
	while (it != con.end())
	{
		result += *it;	// 获得指针的值
		it++;			// 指针指向下一个元素
	}
	return result;
}
