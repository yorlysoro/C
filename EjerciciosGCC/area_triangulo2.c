#include <stdio.h>

int main(void)
{
	int base, altura, resultado;
	
	printf("Programa que calcula el area de un triangulo");
	printf("\nDame la base: ");
	scanf("%d", &base);
	printf("\nDame la altura: ");
	scanf("%d", &altura);
	resultado=(base*altura)/2;
	printf("\nEl resultado es: %d", resultado);
	return 0;
}
