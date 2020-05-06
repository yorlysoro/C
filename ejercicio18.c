#include <string.h>
#include <stdio.h>

int main(void)
{
	char letra;
	char *resp;
	char cad[30];
	
	printf("Cadena: ");
	gets(cad);
	printf("Buscar Letra: ");
	letra = getchar();
	
	resp=strchr(cad,letra);
	
	if(resp)
	printf("%s", resp);
	else
	printf("No esta");
	return 0;
}
