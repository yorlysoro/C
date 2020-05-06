#include <stdio.h>

int main(void)
{
	int x , y;
	
	puts("Introduzca dos numeros");
	scanf("%d %d", &x, &y);
	
	if(x > y)
	printf("%d es mayor a %d\n", x, y);
	else if(y > x)
	printf("%d es mayor a %d\n", y, x);
	return 0;
}
