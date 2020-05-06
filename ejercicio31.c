#include <stdio.h>

int main(void)
{
	int num1 = 0, num2 = 0;
	
	puts("OPor favor introduzca dos numeros para sumarlos");
	scanf("%i", &num1);
	scanf("%i", &num2);
	
	printf("La suma de %d y %d es %d\n", num1, num2, num1 + num2);
	return 0;
}
