#include <stdio.h>

int main(void)
{
	float altutra, base;
	double area;
	
	printf("\nBase del triangulo = ");
	scanf("%f", &base);
	printf("\nAltura del triangulo = ");
	scanf("%f", &altutra);
	area = 0.5 * (double) altutra * base;
	printf("\nArea = %g\n", area);
	return 0;
}
