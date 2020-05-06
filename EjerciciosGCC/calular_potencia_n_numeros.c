#include <stdio.h>
#include <math.h>
int potencia(int x, int y);
int main(void)
{
	int x,y,N,i, result;
	
	printf("Introduzca la cantidad de pares a calcular\n");
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		printf("Ingrese la base: ");
		scanf("%d", &x);
		printf("Ingrese el exponente: ");
		scanf("%d", &y);
		result=potencia(x,y);
		printf("El resultado es: %d\n", result);
	}
	return 0;
}

int potencia(int x, int y)
{
	int result = pow(x,y);
	return result;
}
