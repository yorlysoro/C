#include <stdio.h>
#define MAXVIA 64
#define MAXLINEA 256

int main(void)
{
	//int car;
	FILE *pf;
	char via_acceso[MAXVIA];
	char linea[MAXLINEA];
	printf("\nNombre de ficher que desea leer\n");
	gets(via_acceso);
	if(*via_acceso == '\0')
	printf("No se ha introducido un nombre\n");
	else
	{
		pf = fopen(via_acceso, "r");
		if(pf == NULL)
		{
			printf("\nEl fichero no existe o la ruta no es valida.\n");
		}
		else
		{
			while(fgets(linea,MAXLINEA,pf) != NULL)
			fputs(linea,stdout);
			fclose(pf);
		}
	}
	return 0;
}
