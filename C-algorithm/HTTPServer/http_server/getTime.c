/**
	C语言：打印本地时间
*/
#include <time.h>

void getTime(){
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Time is: %s", asctime(timeinfo));
}