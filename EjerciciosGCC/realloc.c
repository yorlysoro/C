#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	char *cadena;
	int tam;
	tam = (strlen("Primavera")+1) * sizeof(char);
	cadena = (char*)malloc(tam);
	
	strcpy(cadena, "Primavera");
	puts(cadena);
	
	tam += (strlen(" en lupiana\n")+1)*sizeof(char);
	cadena = (char*) realloc(cadena,tam);
	strcat(cadena, " en lupiana\n");
	puts(cadena);
	
	free(cadena);
	return 0;
}
