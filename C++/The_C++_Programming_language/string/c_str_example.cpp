/**
	提供附加定义，避免太多的显示调用 c_str()函数
	
	可以定义：operator const char*() 函数，实现string转换成C风格字符串，但是存在不期望的隐式转换的风险。
*/

extern "C" int atoi(const char *);

int atoi(const string & s)
	{
		return atoi(s.c_str());
	}	

/*
	basic_string<char>的函数：
	
		c_str()	// 返回C风格字符串，包含'\0'
		data()	// 返回char 数组，不包含'\0'
		
		返回值都在string的缓冲区
		
	单独复制，使用copy()
*/

char *c_string(const string &s){
	char *p = new char[s.length() + 1];
	
	s.copy(p, string::npos);
	p[s.length()] = '\0';
	
	
	return p;
}

void f(){
	string s = "abc";
	
	const char *p_array = s.data();
	printf("p_array = %s\n", p_array);
	
	const char *p_str = s.c_str();
	printf("p_str = %s\n", p_str);
}