/*
	复数类的实现
*/
class complex
{
	private:
		double re;
		double im;
		
	public:
		/*
			禁止隐式调用构造函数或者复制运算，可以声明为 private or explicit
		*/
		// 初始化
		complex() : re(0), im(0) {}
		complex(double r) : re(r), im(0) {}
		complex(double r, double i) : re(r), im(i) {}
		// complex(double r=0, double i=0) : re(r), im(i) {}	// 使用默认构造函数
		
		complex(const complex& c) : re(c.re), im(c.im) {}	// 复制构造函数
		
		// 读取实部、虚部
		double real() const 
		{
			return re;
		}
		
		double imag() const
		{
			return im;
		}
		
		// 运算符定义
		complex& operator+=(complex a);
		complex& operator+=(double a)	// 重载，类中定义的自动就是 inline函数
		{
			re += a;
			return *this;
		}
};

inline complex& complex::operator+=(complex a)	// 成员函数
{
	re += a.re;
	im += a.im;
	return *this;
}

// 加法运算符，三个版本都定义了，用户可以灵活使用
complex operator+(const complex a, const complex b)	// 非成员函数
{
	complex r = a;
	return r += b;
}

complex operator+(const complex a, const double b)
{
	complex r = a;
	return r += b;
}

complex operator+(double a, complex b)
{
	complex r = b;
	return r += a;
}

// 其实complex类定义了，一个参数的构造函数，会自动进行类型转换，不需要定义三个版本
bool operator==(complex a, complex b)	// 依赖于转换，只提供一个通用形式
{
	//return (a.re == b.re) && (a.im == b.im);
	return (a.real() == b.real()) && (a.imag() == b.imag());
}

/*
	辅助函数声明
*/
complex operator+(complex, complex);
complex operator+(complex, double);
complex operator+(double, complex);
// -, *, /

// 一元运算符
complex operator-(complex);	// 负号
complex operator+(complex);	// 正好

bool operator==(complex, complex);
bool operator!=(complex, complex);

istream& operator>>(istream&, const complex&);	// 输入
ostream& operator<<(ostream&, const complex&);	// 输出

// 其他有用函数
complex polar(double rho, double theta);
complex conj(complex);

double abs(complex);
double arg(complex);
double norm(complex);

double real(complex);	// 非成员函数
double imag(complex);

complex acos(complex);
complex asin(complex);
complex atan(complex);
