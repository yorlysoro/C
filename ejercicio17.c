#include <stdio.h>
#include <string.h>

int main(void)
{
	int cont;
	char ver_codigo[4];
	char contra[6] = "abcde";
	char tu_contra[6];
	char codigos[10][7];
	
	printf("Contraseña ");
	gets(tu_contra);
	
	if(strcmp(tu_contra,contra))
	{
		printf("Error");
		delay(2000);
		exit(0);
	}
	printf("Introducir codigos\n");
	for(cont = 0; cont < 10; cont++)
	{
		printf("%2.2d: ", cont+1);
		gets(codigos[cont]);
	}
	
	printf("Codigo a listar?");
	gets(ver_codigo);
	
	for(cont = 0; cont < 10; cont++)
	{
		if(!strncmp(ver_codigo, codigos[cont], 3))
		printf("%s\n", codigos[cont]);
	}
	return 0;
	
	
}
