#include <stdio.h>

int main(void)
{
	int n;
	
	puts("Numero\t exp2\t exp3\t exp4");
	puts("-------\t-----\t-----\t-----");
	for(n=0; n<=10; ++n)
		printf("%2d\t%5d\t%5d\t%5d\n", n, n*n, n*n*n, n*n*n*n);
	return 0;
}
