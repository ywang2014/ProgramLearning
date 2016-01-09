/*
	date类的具体实现
*/

Date::Date(int d, Month m, int y)
{
	if (y == 0)
	{
		y = default_date.year();
	}
	if (m == 0)
	{
		m = default_date.month();
	}
	if (d == 0)
	{
		d = default_date.day();
	}
	
	int max_days = getMaxDays(m, y);
	
	if (d < 1 || d > max)
	{
		throw BadDate();
	}
	
	this->y = y;
	this->m = m;
	this->d = d;
}

int Date::getMaxDays(Month mon, int year) const
{
	int max_days = 0;
	
	switch (mon)
	{
		case feb:
			max_days = 28 + leapyear(year);
			break;
		case apr: case jun: case sep: case nov:	// 月份处理方式相同，所以叠在一起
			max_days = 30;
			break;
		case jan: case mar: case may: case jul: case aug: case oct: case dec:
			max_days = 31;
			break;
		default:
			throw BadDate();	// 非法，抛出异常
	}
	
	return max_days;
}

inline int Date::day() const
{
	return d;
}

inline Month Date::month() const
{
	return m;
}

inline int Date::year() const
{
	return y;
}

Date& Date::addYear(int n)
{
	if (n == 0)
	{
		return *this;
	}
	
	y += n;
	return *this;
}

Date& Date::addMonth(int n)
{
	if (n == 0)
	{
		return *this;
	}
	
	/*
	if (n > 0)
	{
		int delta_year = n / 12;
		int mon = m + n % 12;
		if (mon > 12)
		{
			delta_year++;
			mon -= 12;
		}
		
		y += delta_year;
		m = Month(mon);
		
		return *this;
	}
	
	//处理负数n
	return *this;
	*/
	
	int delta_year = n / 12;
	int mon = m + (n - delta_year * 12);	// C++关于负数取模，和实现有关
	if (n > 0)
	{
		if (mon > 12)
		{
			delta_year++;
			mon -= 12;
		}
	}
	else
	{
		// 负数情况
		if (mon < 1)
		{
			delta_year--;
			mon += 12;
		}
		
	}
		
	y += delta_year;
	m = Month(mon);
		
	return *this;
	
}

Date& Date::addMonth(int n)
{
	if (n == 0)
	{
		return *this;
	}
}

inline bool operator==(Date a, Date b)
{
	return (a.day() == b.day()) && (a.month() == b.month()) && (a.year() == b.year());
}




/********************************************************************************************************
	test Date类
*/
void fill(vector<Date>& vec)
{
	while (cin)
	{
		Date d;
		try
		{
			cin >> d;
		}
		catch (Date::BadDate)	// 扑捉的是类型，可以使用匿名对象
		{
			// TODO
			continue;
		}
		
		vec.push_back(d);
	}
}

