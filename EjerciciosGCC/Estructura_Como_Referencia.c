#include <stdio.h>
#include <stdlib.h>
struct Informacion{
	char Nombre[50];
	char Apellidos[50];
	int Edad;
};

void muestra(struct Informacion unapersona);

int main(void)
{
	char xEdad[50];
	struct Informacion xpersona;
	puts("Introduzca su nombre");
	fgets(xpersona.Nombre,50,stdin);
	puts("Introduzca su Apellido");
	fgets(xpersona.Apellidos,50,stdin);
	puts("Introduzca su edad");
	fgets(xEdad,50,stdin);
	xpersona.Edad = atoi(xEdad);
	muestra(xpersona);
	return 0;
	
}

void muestra(struct Informacion unapersona)
{
	printf("Su nombre es: %s\n", unapersona.Nombre);
	printf("Su apellido es: %s\n", unapersona.Apellidos);
	printf("Su Edad es: %d\n", unapersona.Edad);
}
