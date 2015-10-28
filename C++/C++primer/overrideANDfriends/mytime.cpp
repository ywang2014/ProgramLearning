// implement class methods
// 假设构造的数据合法

#include "mytime.h"

Time::Time()
{
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::addHour(int h)
{
	hours += h;
}

void Time::addMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

// 假设构造的数据合法
void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}

/************************ 运算符函数重载 *****************************/
Time Time::operator+(const Time& t) const
{
	Time sum;
	int h = hours + t.hours;
	int m = minutes + t.minutes;
	h += m / 60;
	m %= 60;
	sum.reset(h, m);
	return sum;
}

Time Time::operator-(const Time& t) const
{
	Time diff;
	// 整体转化为分钟考虑，不需要再考虑借位等情况。
	int mins1 = minutes + hours * 60;
	int mins2 = t.minutes + t.hours * 60;
	diff.minutes = (mins1 - mins2) % 60;
	diff.hours = (mins1 - mins2) / 60;
	return diff;
}

Time Time::operator*(double n) const
{
	Time product;
	product.hours = int(hours * n + minutes * n / 60);
	product.minutes = int(minutes * n ) % 60;
	return product;
}

/************************ 友元函数 *****************************/
Time operator*(double n, const Time& t)
{
	//return t * n;
	
	Time pro;
	pro.hours = int(t.hours * n + t.minutes * n / 60);
	pro.minutes = int(t.minutes * n) % 60; 
	
	return pro;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours " << t.minutes << " minutes.";
	return os;	// 可以实现连续输出。
}