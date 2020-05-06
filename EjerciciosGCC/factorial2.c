#include <stdio.h>

int factorial(int a);

int main(void)
{
	int N,a,i;
	puts("\nDe cuantos numeros quiere calcular el factorial");
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		puts("Ingrese el numero: ");
		scanf("%d", &a);
		printf("El factorial de %d es %d\n",a,factorial(a));
	}
	return 0;
}

int factorial(int a)
{
	int i, fact = 1;
	
	for(i = 1; i < a+1; i++)
	{
		fact *= i;
	}
	return fact;
}
