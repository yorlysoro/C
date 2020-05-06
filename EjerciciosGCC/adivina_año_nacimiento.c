#include <stdio.h>


int main(void)
{
	int edad, dia, mes, anyo, anyonac;
	char nombre[40];
	
	printf("Escribe tu nombre: \n");
	scanf("%s", nombre);
	printf("Dime tu edad: \n");
	scanf("%d", &edad);
	printf("Dame la fecha actual(dia/mes/año):\n");
	scanf("%d %d %d",&dia, &mes, &anyo);
	anyonac = anyo - edad;
	printf("Has nacido en %d\n", anyonac);
	return 0;
}
