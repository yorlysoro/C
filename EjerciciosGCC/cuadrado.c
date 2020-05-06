#include <stdio.h>
#define CUAD(x) (x*x)

int main(void)
{
	float a;
	printf("\nEscriba un numero: ");
	scanf("%f", &a);
	printf("\nSu cuadrado es: %f\n", CUAD(a));
	return 0;
}
