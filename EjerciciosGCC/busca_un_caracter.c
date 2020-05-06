#include <stdio.h>
#include <string.h>

int main(void)
{
	char caract,cadena[80], *ptr;
	int posicion;
	
	printf("Introduzca la cadena en donde se va a buscar: \n");
	fgets(cadena,80,stdin);
	printf("Escriba el caracter a buscar:\n");
	caract = getchar();
	ptr=strchr(cadena,caract);
	if(ptr == 0)
	printf("El caracter %c no se encuentra en la cadena\n", caract);
	else
	{
		posicion = ptr-cadena+1;
		printf("La posicion del caracter es %d.\n",posicion );
	}
	return 0;
}
