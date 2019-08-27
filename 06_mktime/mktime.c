#include <stdio.h>
#include <time.h>


void Print(struct tm *gt)
{
	printf("gt->tm_sec  \t:%d \n", gt->tm_sec);
	printf("gt->tm_min  \t:%d \n", gt->tm_min);
	printf("gt->tm_hour  \t:%d \n", gt->tm_hour);			
	printf("gt->tm_mday  \t:%d \n", gt->tm_mday);
	printf("gt->tm_mon+1  \t:%d \n", gt->tm_mon+1);			
	printf("gt->tm_year+1900 :%d \n", gt->tm_year+1900);	
	printf("gt->tm_wday  \t:%d \n", gt->tm_wday);
	printf("gt->tm_yday  \t:%d \n", gt->tm_yday);
	printf("gt->tm_isdst  \t:%d \n", gt->tm_isdst);
}


int main(int argc, char **argv)
{
	if(2 != argc)
		{
			printf("Not Found Param ! \n");
			return -1;
		}

	int param = atoi(argv[1]);			//输入参数

	time_t t = time(NULL);				//获取time_t 格式的时间 (目前时间)

	printf("time :%ld \n", (long)t);

	struct tm *gt;						//把 time_t 格式的时间,转换为 struct tm 格式的时间
	if(1 == param)				
		gt = gmtime(&t);
	else
		gt = localtime(&t);

	Print(gt);

	time_t t2;
	t2 = mktime(gt);					//把 struct tm 格式的时间,转换为time_t 格式的时间
	printf("time2 :%ld \n", (long)t2);

	return 0;

}


