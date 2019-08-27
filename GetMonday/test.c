#include <stdio.h>
#include <string.h>
#include <time.h>

char * GetWeekBeginTime(time_t tNow,  char *str, int len)
{
	time_t tmp_time;
	tmp_time =  (tNow - 316022400) / 604800 * 604800 + 316022400; 	//获取本周周一时间
	struct tm *local_time = NULL;									//转换格式
	local_time = localtime(&tmp_time);
	strftime(str, len, "%Y-%m-%d", local_time);

	return str;
}

/* 字符串(yyyymmdd)转为time_t格式 */
time_t strTotime_t(char *str)
{
	struct tm t;

	printf("Input Date \t:%s \n", str);

	sscanf(str, "%4d-%2d-%2d",
	       &t.tm_year,
	       &t.tm_mon,
	       &t.tm_mday);

	t.tm_year -= 1900;
	t.tm_mon -= 1;

	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;

	return mktime(&t);
}


int main(int argc, char **argv)
{
	if(2 != argc)
		{
			printf("Not Found Param ! \n");
			return -1;
		}

	time_t tmp = strTotime_t(argv[1]);	//字符串转为time_t 格式

	char str_time[100];
	int len = sizeof(str_time)/sizeof(char);

	GetWeekBeginTime(tmp, str_time, len);	//获取本周周一时间

	printf ("Last Monday \t:%s \n", str_time);

	return 0;
}






















