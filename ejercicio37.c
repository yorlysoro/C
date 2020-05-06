#include <stdio.h>

int main(void)
{
	int x = 0, y = 0;
	puts("Introduzca dos numeros");
	scanf("%d %d", &x, &y);
	
	x > y ? printf("%d no es mayor que %d\n", x, y) : printf("%d es mayor que %d\n", x, y);
	return 0;
}
