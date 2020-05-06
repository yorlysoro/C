#include <stdio.h>
#include <string.h>

void insertar(char *cadena, char ca, int n);

int main(void)
{
	char car, cadena[81];
	int posicion;
	printf("\nEscriba una cadena [INTRO], caracter [INTRO], posicion\n");
	gets(cadena);
	scanf("%c\n%d", &car, &posicion);
	insertar(cadena,car,posicion);
	puts(cadena);
}

void insertar(char *cadena, char ca, int n)
{
	char temporal[81];
	strcpy(temporal, &cadena[n-1]);
	cadena[n-1]=ca;
	strcpy(&cadena[n], temporal);
}
