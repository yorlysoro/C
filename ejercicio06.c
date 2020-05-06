#include <stdio.h>

int main(void)
{
	int *p;
	int valor;
	printf("Intriducir valor: ");
	scanf("%i", &valor);
	
	p = &valor;
	
	printf("Direccion de memoria de valor es: %p\n", p);
	printf("El valor de la variable es: %d\n", *p);
	return 0;
}
