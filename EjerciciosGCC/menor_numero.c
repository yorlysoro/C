#include <stdio.h>

int main(void)
{
	int menor, numero1, numero2;
	printf("\nEscribe el primer numero y pulse enter: ");
	scanf("%d", &numero1);
	printf("\nEscriba el segundo numero y pulse enter: ");
	scanf("%d", &numero2);
	if(numero1 < numero2) menor = numero1;
	else menor=numero2;
	
	menor=numero1<numero2 ? numero1 : numero2;
	
	printf("\n El menor de %d y %d es %d\n", numero1, numero2, menor);
	
	return 0;
}
