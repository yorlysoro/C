#include <stdio.h>

int main(void)
{
	int x = 0, y = 0, z = 0;
	
	puts("Introduzca tres numeros:");
	scanf("%d %d %d", &x, &y, &z);
	
	if(x < y && y < z && z > x && z > y)
	puts("Los numero estan en orden numerico");
	else
	puts("Los numeros no estan en orden numerico");
	
	return 0;
}
