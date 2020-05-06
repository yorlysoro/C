#include <stdio.h>

int main(void)
{
	int i, numero, factorial = 1;
	printf("\nEscriba un numero entero para calcular su factorial: ");
	scanf("%d", &numero);
	for(i=numero;i>1;--i) factorial *= i;
	printf("\n%d! = %d\n", numero, factorial);
	return 0;
}
