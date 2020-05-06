#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char letra;
	char *resp;
	char cad[30];
	
	printf("Cadena: ");
	gets(cad);
	printf("Buscar letra: ");
	letra=getchar();
	
	resp=strrchr(cad, letra);
	if(resp)
	printf("%s", resp);
	else
	printf("No esta");
	return 0;
}
