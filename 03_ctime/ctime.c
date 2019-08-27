#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
	time_t t = time(NULL);
	char *ct = NULL;
	
	ct = ctime(&t);
	printf("ctime :%s", ct);

	return 0;
}
