#include <stdio.h>

int main(void)
{
	int x, y, a, b, c, d, e, f;
	
	puts("Introduzca los valores de a, b, c, d, e, f");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	
	x = (c*e - b*f) / (a*e - b*d);
	y = (a*f - c*d) / (a*e - b*d);
	
	printf("El valor de x es %d\n"
	"El valor de y es %d\n", x, y);
	return 0;
}
