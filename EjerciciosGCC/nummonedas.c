#include <stdio.h>
#define LIM 8

int monedas[LIM] = {500,200,100,50,25,10,5,1};

int main(void)
{
	int num, cantidad, numonedas;
	printf("Introduzca el importe exacto: ");
	scanf("%d", &cantidad);
	printf("El cambio optimo es el siguiente: \n");
	for(num = 0; num<LIM; num++)
	{
		numonedas = cantidad/monedas[num];
		if(numonedas != 0) printf("%d de %d\n", numonedas, monedas[num]);
		cantidad = cantidad % monedas[num];
	}
	return 0;
}
