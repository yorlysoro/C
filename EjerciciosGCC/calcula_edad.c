#include <stdio.h>

int main(void)
{
	int fnac, fact, edad;
	printf("Introduce tu año de nacimiento: ");
	scanf("%d", &fnac);
	printf("Introduce el año actual: ");
	scanf("%d", &fact);
	edad = fact-fnac;
	printf("\nTu edad es: %d\n", edad);
	return 0;
}
