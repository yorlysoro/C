#include <stdio.h>
#include <string.h>

int main(void)
{
	int tamanintcad;
	char cadena[100];
	char cadena2[1][10] = {"hola\n"};
	int v;
	
	fgets(cadena,100,stdin);
	tamanintcad = strlen(cadena);
	
	printf("%d\n", tamanintcad);
	//tamanintcad = sizeof(cadena);
	v = strcmp(cadena2[0],cadena);
	
	printf("%d\n", v);
	
	return 0;
}
