#include <stdio.h>
int main(void)
{
	int c, n=0;
	FILE *pf;
	char *nombre = "Archivo.txt";
	
	if((pf = fopen(nombre, "rt")) == NULL )
	{
		puts("Error en al operacion de apertura");
		return 1;
	}
	while((c = getc(pf)) != EOF)
	{
		if(c == '\n')
		{
			n++; putchar('\n');
		}
		else
		putchar(c);
		
	}
	printf("\nNumero de lineas del archivo: %d",n);
	fclose(pf);
	return 0;
		
}
