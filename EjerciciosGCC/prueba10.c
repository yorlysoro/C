#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	unsigned int num;
	srand(time(NULL));
	num = 2 + (rand() % 3);
	
	printf("%d\n", num);
	return 0;
}
