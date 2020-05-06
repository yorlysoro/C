#include <stdio.h>
#define MAX_RADIO 2.0
#define PI 3.141592

double AreaCirculo(double radio);
double AreaEsfera(double radio);

int main(void)
{
	double radio;
	puts("\n\t=== Tabla de Areas ===\n");
	puts("\tRadio\tCirculo\tEsfera");
	puts("\t------\t-------\t");
	for(radio=0.0;radio <= (double) MAX_RADIO; radio+=0.2)
	printf("\t%6.2f\t%6.3f\t%6.3f\n", radio, AreaCirculo(radio), AreaEsfera(radio));
	
	return 0;
}

double AreaCirculo(double radio)
{
	double area;
	area = PI * (radio * radio);
	
	return(area);
}

double AreaEsfera(double radio)
{
	double area;
	area = 4.00 * PI * (radio * radio);
	return(area);
}
