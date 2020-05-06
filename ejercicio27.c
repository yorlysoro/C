#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	int i,j;
	float resultado;
	
	puts("Division y Modulo:");
	puts("1 o 2");
	
	scanf("%i", &a);
	
	if(a == 1)
	{
		puts("Introduce el denominador y el numerador:");
		scanf("%i ", &i);
		scanf("%i ", &j);
		if(j != 0)
		{
			resultado = i / j;
			printf("EL resultado de %i / %j es %f\n", i, j, resultado);
		}
		else
		{
			puts("Error no se puede dividir entre 0");
			exit(EXIT_FAILURE);
		}
	}
	else if(a == 2)
	{
		puts("Introduce el numerador y el denominador:");
		scanf("%i ", &i);
		scanf("%i ", &j);
		if(j != 0)
		{
			resultado = i % j;
			printf("El resultado de %i %% %j es %f\n", i, j, resultado);
		}
		else
		{
			puts("Error no se puede dividir entre 0");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		puts("Error! Selecciona d o m");
		exit(EXIT_FAILURE);
	}
	return 0;
			
		
	
}
