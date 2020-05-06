#include <stdio.h>

int main(void)
{
	int col1 =1, col2 = 100;
	
	while(col1 <= 100)
	{
	printf("%d\t%d\n", col1, col2);
	col1++;
	col2--;
	}
	puts("listo");
	return 0;
}
