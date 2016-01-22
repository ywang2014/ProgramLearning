/*
	Theme 1.复制赋值运算符函数
	
	如下为类型CMyString的声明，请为该类型添加复制运算符函数
*/ 
class CMyString
{
	public:
		CMyString(char* pData = NULL);
		CMyString(const CMyString& str);
		~CMyString(void);
		
		CMyString& operator=(const CMyString& str);
		
	private:
		char* m_pData;
};

CMyString::CMyString(char* pData)
{
	if (pData == NULL)
	{
		m_pData = new char[1];
		*m_pData = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
	
	//char* d_ptr = m_pData;
	//char* s_ptr = pData;
	// while (*d_ptr++ = *s_ptr++) ;
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[str.size() + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void)
{
	delete[] m_pData;
}

// 初级入门
CMyString& CMyString::operator=(const CMyString& str)
{
	if (*this == str)
	{
		return *this;
	}
	
	delete[] m_pData;
	
	m_pData = new char[str.size() + 1];
	
	strcpy(m_pData, str.m_pData);
	
	return *this;
}

// 高级程序员，考虑异常安全性，鲁棒性更好
CMyString& CMyString::operator=(const CMyString& str)
{
	if (*this != str)
	{
		CMyString str_temp(str);	// 依赖于局部对象的复制构造函数申请资源，和析构函数释放资源
		
		char* ptr_temp = str_temp.m_pData;
		str_temp.m_pData = m_pData;
		m_pData = ptr_temp;
	}
	
	return *this;
}
