#include <stdio.h>
#include <math.h>

int main(void)
{
	double radianes;
	printf("Introducir radianes: ");
	scanf("%f", &radianes);
	printf("Coseno = %f\n", cos(radianes));
	printf("Seno = %f\n", sin(radianes));
	printf("Tangente = %f\n", tan(radianes));
	return 0;
}
