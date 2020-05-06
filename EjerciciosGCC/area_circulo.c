#include <stdio.h>
#define PI 3.1415

int main(void)
{
	float area = 2;
	int radio = 0;
	
	printf("Introduzca el radio del circulo: ");
	scanf("%d", &radio);
	area = PI*radio*radio;
	printf("El area del circulo de radio = %d es %f\n", radio, area);
	return 0;
}
