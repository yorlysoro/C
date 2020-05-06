#include <stdio.h>
#include <string.h>

typedef struct tiposdedatos{
	int numeros;
	char letras[1000];
	float concoma;
}datos;
int main(void)
{	
	datos entero;
	datos cadena;
	datos coma;
	entero.numeros = 10;
	coma.concoma = 3.1415;
	strcpy(cadena.letras, "Hola");
	printf("%d\n", entero.numeros);
	printf("%s\n", cadena.letras);
	printf("%f\n", coma.concoma);
	return 0;
}
