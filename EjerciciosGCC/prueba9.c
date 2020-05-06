#include <stdio.h>

int main(void)
{
	int x = 0,y = 0;
	static char palabras[2][2][30] = { {"Nombres: ", {"Jose"} },
								{ "Apellido: ", {"Hola"} } };
	//printf("%s ", palabras[1][0]);
	for(x = 0; x < 2;x++ )
	{
		printf("%s ", *palabras[x]);
		for(y = 1; y < 2; y++)
		{
			printf("%s", palabras[x][y]);
			y++;
		}
		
		putchar('\n');
	}	
	return 0;
}
