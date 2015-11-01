/**
*  阴历数据结构
*   阳历1900.1.31＝阴历0.1.1
*   2000.2.5 = 0.1.1 星期六
*/

const int YEAR = 1900;
const int MONTHS[13] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    // 闰年2月29天，需要加1天。

/***********************************************************************************

数据结构:
    共使用17位数据
    第17位：表示闰月天数，0表示29天   1表示30天
    第16位-第5位（共12位）表示12个月，其中第16位表示第一月，如果该月为30天则为1，29天为0
    第4位-第1位（共4位）表示闰月是哪个月，如果当年没有闰月，则置0

*****************************************************/
static int LunarDateArray[] = {
            0x04BD8,0x04AE0,0x0A570,0x054D5,0x0D260,0x0D950,0x16554,0x056A0,0x09AD0,0x055D2,
            0x04AE0,0x0A5B6,0x0A4D0,0x0D250,0x1D255,0x0B540,0x0D6A0,0x0ADA2,0x095B0,0x14977,
            0x04970,0x0A4B0,0x0B4B5,0x06A50,0x06D40,0x1AB54,0x02B60,0x09570,0x052F2,0x04970,
            0x06566,0x0D4A0,0x0EA50,0x06E95,0x05AD0,0x02B60,0x186E3,0x092E0,0x1C8D7,0x0C950,
            0x0D4A0,0x1D8A6,0x0B550,0x056A0,0x1A5B4,0x025D0,0x092D0,0x0D2B2,0x0A950,0x0B557,
            0x06CA0,0x0B550,0x15355,0x04DA0,0x0A5B0,0x14573,0x052B0,0x0A9A8,0x0E950,0x06AA0,
            0x0AEA6,0x0AB50,0x04B60,0x0AAE4,0x0A570,0x05260,0x0F263,0x0D950,0x05B57,0x056A0,
            0x096D0,0x04DD5,0x04AD0,0x0A4D0,0x0D4D4,0x0D250,0x0D558,0x0B540,0x0B6A0,0x195A6,
            0x095B0,0x049B0,0x0A974,0x0A4B0,0x0B27A,0x06A50,0x06D40,0x0AF46,0x0AB60,0x09570,
            0x04AF5,0x04970,0x064B0,0x074A3,0x0EA50,0x06B58,0x055C0,0x0AB60,0x096D5,0x092E0,
            0x0C960,0x0D954,0x0D4A0,0x0DA50,0x07552,0x056A0,0x0ABB7,0x025D0,0x092D0,0x0CAB5,
            0x0A950,0x0B4A0,0x0BAA4,0x0AD50,0x055D9,0x04BA0,0x0A5B0,0x15176,0x052B0,0x0A930,
            0x07954,0x06AA0,0x0AD50,0x05B52,0x04B60,0x0A6E6,0x0A4E0,0x0D260,0x0EA65,0x0D530,
            0x05AA0,0x076A3,0x096D0,0x04BD7,0x04AD0,0x0A4D0,0x1D0B6,0x0D250,0x0D520,0x0DD45,
            0x0B5A0,0x056D0,0x055B2,0x049B0,0x0A577,0x0A4B0,0x0AA50,0x1B255,0x06D20,0x0ADA0,
            0x14B63};


class LunarHoliday
{
public:
    int month;
    int day;
    int year;

public:
    LunarHoliday()
    {
        LunarHoliday(0);
    }

    LunarHoliday(int n)
    {
        day = n % 100;
        n /= 100;
        month = n % 100;
        year = n / 100;
    }
};

class SolarHoliday
{
public:

    int month;
    int day;
    int year;

    int days;

    SolarHoliday()
    {
        LunarHoliday(0);
    }

    SolarHoliday(int n)
    {
        day = n % 100;
        n /= 100;
        month = n % 100;
        year = n / 100;
    }
};


int getLeapMonth(int n)
{
    int month = n & 0xf;
    return month;   // 0表示没有闰月
}

int getLeapMonthDays(int n)
{
    int temp = (n >> 16);
    if (temp == 1)
    {
        return 30;  // 闰月大
    }
    return 29;
}

int getLunarMonthDays(int n, int i)
{
    int temp = n >> (3 + i);
    if ((temp & 1) == 1)
    {
        return 30;  // 月大
    }
    return 29;
}

// 获得阴历年的一年天数
int getLunarYearDays(int year)
{
    int days = 0;
    int index_year = year - YEAR;   // 查表的索引
    int l_year = LunarDateArray[index_year];
    for (int i = 0; i <= 12; i++)
    {
        days += getLunarMonthDays(l_year, i);
    }
    if (getLeapMonth(l_year) != 0)  // 判断有没有闰月
    {
        days += getLeapMonthDays(l_year);
    }

    return days;
}

bool isLeap(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 != 0 && year % 4 == 0)
    {
        return true;
    }
    return false;
}


// 获取任意年份到1900.1.1的天数。
int getDays(int n)
{
    int days = 0;
    SolarHoliday sh(n);

    if(sh.year < YEAR)
    {
        return -1;
    }

    for (int i = YEAR; i < sh.year; i++)
    {
        if (isLeap(i))
        {
            days += 366;
        }
        else
        {
            days += 365;
        }
    }

    for (int i = 1; i < sh.month; i++)
    {
        days += MONTHS[i];
    }

    if (sh.month > 2 && isLeap(sh.year))
    {
        days += MONTHS[0];
    }
    days += sh.day - 1;     // 1900.1.1开始计算

    return days;
}

