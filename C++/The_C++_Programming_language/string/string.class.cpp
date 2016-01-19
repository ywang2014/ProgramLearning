/*
	string 类
	
	辅助类：
		srep: 使一个实际表示能够被几个具有同样值的string所共享
		range: 在出现错误时，抛出异常
		cref: 实现下标运算，区别对待读写操作
*/
class String
{
	private:
		struct Srep;	// 表示
		Srep *rep;
	public:
		class Cref;		// 引用char
		class Rang{};	// 异常
		
		String();
		String(const char*);
		String(const String&);
		String& operator=(const char*);
		String& operator=(const String&);
		~String();
		
		void check(int i) const
		{
			if (i < 0 || rep->sz <= i)
			{
				throw Rang();
			}
		}
		
		char read(int i) const	// 无检查，直接访问
		{
			return rep->s[i];
		}
		
		void write(int i, char c)
		{
			rep = rep->get_own_copy();
			rep->s[i] = c;
		}
		
		Cref operator[](int i)	// 安全检查，再访问
		{
			check(i);
			return Cref(*this, i);
		}
		
		char operator[](int i) const	// 安全检查，再访问
		{
			check(i);
			return rep->s[i];
		}
		
		int size() const
		{
			return rep->sz;
		}
		
		String& operator+=(const String&);
		String& operator+=(const char*);
		
		friend ostream& operator<<(ostream&, const String&);
		friend istream& operator>>(istream&, String&);
		
		friend bool operator==(const String& str, const char* s)
		{
			return strcmp(str.rep->s, s) == 0;
		}
		friend bool operator==(const String& str1, const String& str2)
		{
			return strcmp(str1.rep->s, str2.rep->s) == 0;
		}
		friend bool operator!=(const String& str, const char* s)
		{
			return strcmp(str.rep->s, s) != 0;
		}
		friend bool operator!=(const String& str1, const String& str2)
		{
			return strcmp(str1.rep->s, str2.rep->s) != 0;
		}
		
};

struct String::Srep
{
	char* s;	// 到元素的指针
	int sz;		// 字符个数
	int n;		// 引用计数
	
	Srep(int nsz, const char* p)
	{
		n = 1;
		sz = nsz;
		s = new char[sz+1];	// 结束符 '\0'
		strcpy(s, p);
	}
	~Srep()
	{
		delete[] s;
	}
	
	Srep* get_own_copy()	// 写时复制
	{
		if (n == 1)
		{
			return this;
		}
		else
		{
			n--;
			return new Srep(sz, s);
		}
	}
	
	void assign(int nsz, const char* p)
	{
		if (sz != nsz)
		{
			delete[] s;
			sz = nsz;
			s = new char[sz+1];
		}
		strcpy(s, p);
	}
	private:
		Srep(const Srep&);	// 禁止复制构造
		Srep& operator=(const Srep&);	// 禁止复制赋值
};

String::String()	// 默认构造函数，以空串作为默认值
{
	rep = new Srep(0, "");
}

String::String(const String& s)	// 复制构造函数
{
	x.rep->n++;	// 添加引用计数
	rep = x.rep;	// 直接共享指针
}

String::~String()
{
	if (--rep->n == 0)
	{
		delete rep;
	}
}

String& String::operator=(const String& s)	// 复制赋值运算符
{
	x.rep->n++;	// 保护，防止赋值给自身????
	if (--(rep->n) == 0)	// 等于1，说明刚刚新创建的临时变量
	{
		delete rep;
	}
	
	rep = x.rep;	// 共享表示
	return *this;
}

String::String(const char* s)
{
	rep = new Srep(strlen(s), s);
}

String& String::operator=(const char* s)
{
	if (rep->n == 1)	// 直接使用即可
	{
		rep->assign(strlen(s), s);
	}
	else
	{
		rep->n--;
		rep = new Srep(strlen(s), s);
	}
	return *this;
}

class String::Cref
{
	friend class String;
	String& s;
	int i;
	
	Cref(String& str, int ii) : s(str), i(ii) {}
	
	public:
		operator char() const	// 转换函数，自动转换为字符类型
		{
			return s.read(i);
		}
		
		void operator=(char c)
		{
			s.write(i, c);
		}
}


String& String::operator+=(const String& str)
{
	
	if (rep->n > 1)	// 写时复制，解除共享
	{
		rep->n--;
		rep = new Srep(strlen(rep->sz), rep->s);	// 创建一个新的完全相同的变量
	}
	
	// 否则直接修改
	rep->sz += str.rep->sz;		// 新字符串字符数
	rep->assign(strlen(rep->sz), rep->s);	// 重新分配空间
	strcat(rep->s, str.rep->s);	// 合并
	
	return *this;
}

String& String::operator+=(const char* s)
{
	if (rep->n > 1)	// 写时复制，解除共享
	{
		rep->n--;
		rep = new Srep(strlen(rep->sz), rep->s);	// 创建一个新的完全相同的变量
	}
	
	// 否则直接修改
	rep->sz += strlen(s);		// 新字符串字符数
	rep->assign(strlen(rep->sz), rep->s);	// 重新分配空间
	strcat(rep->s, s);	// 合并
	
	return *this;
}

String operator+(const String& str1, const String& str2)
{
	String result;
	result += str1;
	result += str2;
	return result;
}

String operator+(const String& str, const char* s)
{
	String result;
	result += str;
	result += s;
	return result;
}


// test 
int hash(const String& s)
{
	int h = s.read(0);	// 不检查范围
	const int max = s.size();
	for (int i = 1; i < max; i++)
	{
		h ^= s.read(i) >> 1;	// 不检查越界问题，直接访问
	}
	return h;
}

void f(String s, const String& r)
{
	char c = s[1];	// s.operator[](1).operator char()
	s[1] = 'c';		// s.operator[](1).operator=('c')
	
	char c2 = r[1];	// r.operator[](1)
	r[1] = 'd';		// 错误，const不能赋值，r.operator[](1) = 'd'
}

// 主程序
String fn(String a, String b)
{
	a[2] = 'x';
	char c = b[3];
	cout << "in fn: " << a << " " << b << " " << c << "\n";
	return b;
}

int main()
{
	String x, y;
	cout << "Please enter two string\n";
	cin >> x >> y;
	cout << "input: " << x << " " << y << "\n";
	String z = x;
	
	y = fn(x, y);
	if (x != z)
	{
		cout << "x corrupted!\n";
	}
	x[0] = '!';
	if (x == z)
	{
		cout << "write failed!\n";
	}
	
	cout << "exit: " << x << " " << y << " " << z << "\n";
	
	return 0;
} 