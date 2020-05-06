#include <stdio.h>
#include <string.h>

int main(void)
{
	char caract, cadena[80], *ptr;
	printf("Introduzca la cadena dende se va a buscar: \n");
	gets(cadena);
	printf("Escriba el caracter a buscar:\n");
	caract=getchar();
	ptr=strchr(cadena, caract);
	if(ptr == 0) printf("El caracter %c no se encuentra en la cadena.\n", caract);
	else printf("La posicion del caractere es %ld.\n", ptr-cadena );
	return 0;
}
