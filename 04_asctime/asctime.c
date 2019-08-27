#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
	if(2 != argc)
		{
			printf("Not Found Param ! \n");
			return -1;
		}

	int param = atoi(argv[1]);
	
	time_t t= time(NULL);		//获取当前时间
	
	struct tm *gt;
	
	if(1 == param)
		gt = gmtime(&t);		//把当前时间转换为struct tm 格式 :获取的是UTC时间：没有经过时区转换	
	else
		gt = localtime(&t); 	//把当前时间转换为struct tm 格式 :获取的是本地时间：经过时区转换之后的
	
	
	char *asct;
	asct = asctime(gt);			//把当前时间转换为字符串格式

	printf("asctime :%s",asct);
	return 0;
}
