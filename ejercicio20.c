#include <stdio.h>
#include <string.h>

int main(void)
{
	char letras[5];
	char *resp,
	char cad[30];
	
	printf("Introducir cadena: "); gets(cad);
	printf("Posibles letras(4): "); gets(letras);
	resp=strpbrk(cad, letras);
	if(resp)
	printf("%s", resp);
	else
	printf("Error");
	return 0;
}
