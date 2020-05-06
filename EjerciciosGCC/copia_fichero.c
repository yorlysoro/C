#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *origen, *destino;
	char car, aux1, aux2;
	int i = 0, igu = 1;
	if(argc != 3)
	{
		printf("Error. La instruccion es: \n copia fichero orgen fichero destino\n" );
		exit(1);
	}
	do
	{
		aux1 = *(argv[1]+i);
		aux2 = *(argv[2]+i);
		if(aux1 != aux2)
		{
			igu=0;
			break;
		}
		i++;
	}while(aux1 != '\0' ||  aux2 !=  '\0');
	if(igu == 1)
	{
		printf("El fichero destino es el mismo que el fichero origen\n");
		exit(2);
	}
	origen=fopen(argv[1], "r");
	destino=fopen(argv[2],"w");
	if(origen==NULL || destino==NULL )
	{
		printf("El fichero de origen no existe o no espacio en el disco\n");
		exit(3);
	}
	while((car = getc(origen)) != EOF) putc(car,destino);
	
	fclose(origen);
	fclose(destino);
	return 0;	
}
