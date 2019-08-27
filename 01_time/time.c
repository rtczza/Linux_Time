#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
	time_t t= time(NULL);
	
	printf("time :%ld\n",(long)t);

	return 0;
}
