#include "../include/config.h"
#include <bits/types/time_t.h>
#include <cstdio>
#include <iostream>
#include <time.h>

int main()
{
	//"date": "Fri Jan 15 2021 07:01:00 GMT+0800 (中国标准时间)",
	//
	time_t tt;
	time(&tt);
	tt+= 8*3600;
	tm *ts = gmtime(&tt);

	printf("%d-%d-%d %d:%d:%d\n",ts->tm_year+1900,ts->tm_mon+1,ts->tm_mday+1,ts->tm_hour,ts->tm_min,ts->tm_sec);

	//2021-1-21 14:38:25

    return 0;
}
