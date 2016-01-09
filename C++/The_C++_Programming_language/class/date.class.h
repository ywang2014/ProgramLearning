#include <string>

class Date
{
public:	// 公用API
	enum Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
	};
	class BadDate{};	// 异常类
	Date(int day = 0, Month mon = Month(0), int year = 0);	// 0 代表取默认值
	
	// 检查date的函数
	int day() const;
	Month month() const;
	int year() const;
	
	string string_rep() const;	// 字符串表示
	void char_rep(char s[]) const;	// C风格的字符串表示
	
	static void set_default(int, Month, int);
	
	// 修改Date的函数
	Date& addYear(int n);
	Date& addMonth(int n);
	Date& addDay(int n);
	
	// 重载运算符
	bool operator==(Date a)
	{
		// 调用定义好的函数就可。 operator==(Date a, Date b)
		return *this == a;
	}
	
private:	// 私有数据
	int d;
	int m;
	int y;
	static Date default_date;
	int getMaxDays(Month mon, int year) const; 	// 协助函数更好
}

/*
	封装在一个名称空间中
	
	处理时间的各种功能
*/
namespace Chrono
{
	class Date2
	{
		...
	};
	int diff(Date2 a, Date2 b);
	bool leapyear(int y);
	Date2 nextWeekday(Date2 d);
	Date2 nextSaturday(Date2 d);
}