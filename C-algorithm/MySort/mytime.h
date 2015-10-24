#ifndef MYTIME_H
#define MYTIME_H

#include <time.h>
#include <stdio.h>

void get_time()
{
    time_t now;
    struct tm *time_info;
    time(&now); // 获取当前时间
    time_info = localtime(&now);    // 转化为当地时间

    int year, month, day, hour, minute, second;
    year = time_info->tm_year + 1900;
    month = time_info->tm_mon + 1;
    day = time_info->tm_mday;
    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;

    printf("%d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);

}

void get_msec()
{
    // 系统计时器，单位毫秒
    clock_t msec = clock();
    printf("%ld\n", msec);
}


#endif // MYTIME_H
