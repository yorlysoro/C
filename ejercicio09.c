#include <stdio.h>
int main(void)
{
	char *apellidos;
	printf("Introducir apellidos: ");
	gets(apellidos);
	
	printf("Tus apellidos son: %s\n", apellidos);
	printf("La direccion de memoria es: %p\n", apellidos);
	return 0;
}
