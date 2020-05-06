#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Datos{
	int Enteros;
	float Flotantes;
}dato;

typedef struct Conversion{
	char numeros[50];
}xconversion;


dato Entrada(dato *xDatos);
void Muestra(dato xDato);

int main(void)
{
	dato Datox;
	Datox = Entrada(&Datox);
	Muestra(Datox);
	return 0;
}

dato Entrada(dato *xDatos)
{
	xconversion xconver[2];
	
	strcpy(xconver[0].numeros, "10");
	strcpy(xconver[1].numeros, "2.5");
	
	xDatos->Enteros = atoi(xconver[0].numeros);
	xDatos->Flotantes = atof(xconver[1].numeros);
	
	return *xDatos;

}

void Muestra(dato xDato)
{
	printf("Estos es un entero: %d\n", xDato.Enteros);
	printf("Esto es un flotante:%.2f\n", xDato.Flotantes);
}
