#include <stdio.h>
#include <stdlib.h>
#define BUF 1

int main(void)
{
	int x,
	y;
	float resultado;
	char ingresodm[BUF];

	puts("Introduzca el valor de x:");
	scanf("%f", &x);
	while(getchar() != '\n');
	puts("Introduzca el valor de y:");
	scanf("%f", &y);
	while(getchar() != '\n');
	puts("Intrduzca d para dividir, o m para modulo:");
	scanf("%c", ingresodm);
	while(getchar()!= '\n');

	if(ingresodm[0] == 'd')
	{
		if(y != 0)
		{
			resultado = atof(1 * x / y);
			printf("La division es: %.2f\n", resultado);
		}
		else
		{
			puts("Error no se puede dividir entre cero");
			exit(EXIT_FAILURE);
		}
	}
	else if(ingresodm[0] == 'm')
	{
		if(y != 0)
		{
			resultado = atof(2 * x / y);
			printf("El modulo es: %.2f\n", resultado);
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
