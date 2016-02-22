/**
	自定义函数对象
	
	只需要重载 "()": operator() 函数即可。
	
*/

// 例如重载比较函数，用于排序等
class cmp_Nocase	// 忽略大小写的比较函数对象，相当于重载的是小于号
{
	public:	// public任意对象都能访问
		bool operator()(const string& str1, const string str2) const
		{
			// 使用迭代器访问
			string::const_iterator it1 = str1.begin();
			string::const_iterator it2 = str2.begin();
			
			while (it1 != str1.end() && it2 != str2.end() && toupper(*it1) == toupper(*it2))
			{
				it1++;
				it2++;
			}
			
			if (it1 == str1.end())
			{
				return it2 != str2.end();
			}
			else if (it2 == str2.end())
			{
				return false;
			}
			else
			{
				return toupper(*it1) < toupper(*it2);
			}
		}
};

// 使用
sort(con.begin(), con.end(), cmp_Nocase());

/*
	可以直接使用 struct，即默认的成员都是public的类
*/
struct Cstr_less
{
	bool operator()(const char* ch1, const char* ch2) const
	{
		return strcmp(ch1, ch2) < 0;
	}
};

// 构造哈希表
map<char*, int, Cstr_less>  hash_table;