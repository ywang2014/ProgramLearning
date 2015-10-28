/**********************************
*  类的定义与实现
*	数据隐藏和接口定义：数据成员全部private，方法public
*	
*	运算符的重载：operator*()
*	
*	友元函数：friend 
*
*/

#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class Time
{
	private:
		int hours;
		int minutes;
		
	public:
		Time();
		Time(int h, int m);
		void addHour(int h);
		void addMin(int m);
		void reset(int h, int m);
		
		Time operator+(const Time& t) const;
		Time operator-(const Time& t) const;
		Time operator*(const double n) const;
		
		friend Time operator*(double n, const Time& t);
		friend std::ostream& operator<<(std::ostream& os, const Time& t);
		
};

#endif