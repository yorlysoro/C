#include <stdio.h>

int main(void)
{
	int col, fil;
	
	for(col = 1; col <=24; col++)
	{
		printf("*");
		if(col == 13)
		{
			for(fil = 1; fil <= 4; fil++)
			printf("\n*%24c", '*');
			puts(" ");
		}
		printf("*");
	}
	puts(" ");
	return 0;
}
