#include <stdio.h>
#include <stdlib.h>
#define BUF 4

int main(void)
{
	int x,
		y,
		resultado;
	char ingresox[BUF],
		 ingresoy[BUF],
		 ingresodm[BUF];
	
	printf("Introduzca el valor de x:");
	
	fgets(ingresox, BUF - 1, stdin);
	
	printf("Introduzca el valor de y:");
	
	fgets(ingresoy, BUF - 1, stdin);
	
	printf("Intrduzca d para dividir, o m para modulo:");
	
	scanf("%c", ingresodm);
	
	x = atoi(ingresox);
	y = atoi(ingresoy);
	
	if(ingresodm[0] == 'd')
	{
		if(y == 0)
		{
			puts("Error no se puede dividir entre cero");
			exit(EXIT_FAILURE);
		}
		else
		{
			resultado = 1 * x / y;
			printf("La division es: %i\n", resultado);
		}
	}
	else if(ingresodm[0] == 'm')
	{
		if(y != 0)
		{
			resultado = 2 * x % y;
			printf("El modulo es: %i\n", resultado);
		}
		else
		{
			puts("Error no se puede dividir entre cero");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		puts("Error elija d o m");
		exit(EXIT_FAILURE);
	}
	return 0;
}
