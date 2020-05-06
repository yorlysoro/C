#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *pf;
	char nm[] = "Hola.txt";
	
	pf = fopen(nm, "r");
	if(pf == NULL)
	{
		puts("Error al abrir el archivo");
		exit(1);
	}
	return 0;
}
