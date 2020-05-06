#include <stdio.h>

int main(void)
{
	enum moneda{dolar,penique=100,medio=50,cuarto=25};
	enum moneda dinero;
	
	printf("Valor de la moneda: ");
	scanf("%i", &dinero);
	
	switch(dinero)
	{
		case dolar:
			printf("Con ese valor es un Dolar");
			break;
		case penique:
			printf("Con ese valor es un penique");
			break;
		case medio:
			printf("Con ese valor es un medio");
			break;
		case cuarto:
			printf("Con ese valor es un cuarto");
			break;
		default:
		printf("Moneda Inexistente");
	}
	return 0;
}
