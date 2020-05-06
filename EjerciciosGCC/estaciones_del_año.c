#include <stdio.h>
#include <string.h>

enum Meses
{
	Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre
};

typedef struct Estaciones{
	char xEstacion[30];
}xestacion;


int main(void)
{
	xestacion estacion[5];
	int enume = Noviembre;
	
	switch(enume)
	{
		case Diciembre:
		case Enero:
		case Febrero:
		case Marzo:
		printf("Es %s\n", strcpy(estacion[0].xEstacion, "Invierno"));
		break;
		case Abril:
		case Mayo:
		case Junio:
		printf("Es %s\n",strcpy(estacion[1].xEstacion, "Primavera"));
		break;
		case Julio:
		case Agosto:
		case Septiembre:
		printf("Es %s\n", strcpy(estacion[2].xEstacion,"Verano"));
		break;
		case Octubre:
		case Noviembre:
		printf("Es %s\n", strcpy(estacion[3].xEstacion, "Otoño"));
		break;
	}
	
	
	return 0;
}
