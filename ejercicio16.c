#include <stdio.h>
#include <string.h>

int main(void)
{
	char *origen, destino[20];
	printf("Introducir Origen: ");
	gets(origen);
	strcpy(destino,origen);
	printf("%s\n%s\n\n", destino, origen);
	memset(destino, '\0', 20);
	memset(destino, 'x', 6);
	
	if(strlen(origen)<14)
	{
		printf("Se pueden concatenar\n");
		strcat(destino,origen);
	}
	else
	printf("No se pueden concatenar\n");
	
	printf("%s\n", destino);
	return 0;
}
