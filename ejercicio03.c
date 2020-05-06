#include <stdio.h>

int main(void)
{
	char texto[10][80];
	int indice;
	
	for(indice=0;indice<10;indice++)
	{
		printf("%2.2d\n", indice+1);
		gets(texto[indice]);
	}
	puts("Pulsa tecla");
	
	for(indice=0;indice<10;indice++)
	printf("%s\n", texto[indice]);
	
	return 0;
}
