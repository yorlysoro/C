#include <stdio.h>

int main(void)
{
	int col, fil;
	
	for(col = 1; col <=24; col++)
	{
		printf("*");
		if(col == 13)
		{
			for(fil = 1; fil <= 6; fil++)
			{
				printf("\n*%24c", '*');
				puts(" ");
				if(fil == 3)
				printf("\n*%12s%12c", "Hola", '*');
			}
		}
		printf("*");
	}
	puts(" ");
	return 0;
}

