#include <stdio.h>
#include <time.h>

int main()
{
	time_t t = time(NULL);

	printf("time :%ld \n", (long)t);

	struct tm *gt;

	gt = gmtime(&t);

	printf("gt->tm_sec  \t:%d \n", gt->tm_sec);
	printf("gt->tm_min  \t:%d \n", gt->tm_min);
	printf("gt->tm_hour  \t:%d \n", gt->tm_hour);		//是UTC时间，未经时区转换
	printf("gt->tm_mday  \t:%d \n", gt->tm_mday);
	printf("gt->tm_mon+1  \t:%d \n", gt->tm_mon+1);			//范围是0-11
	printf("gt->tm_year+1900 :%d \n", gt->tm_year+1900);	//从1900年开始的年数
	printf("gt->tm_wday  \t:%d \n", gt->tm_wday);
	printf("gt->tm_yday  \t:%d \n", gt->tm_yday);
	printf("gt->tm_isdst  \t:%d \n", gt->tm_isdst);

	return 0;

}