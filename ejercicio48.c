#include <stdio.h>

int main(void)
{
	int num1, num2, num3;
	
	puts("introuzca tres numeros");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	if(num1 < num2 && num2 < num3)
	puts("Estos numeros estan en orden");
	else
	puts("Los nmumero no estan en orden");
	return 0;
}
