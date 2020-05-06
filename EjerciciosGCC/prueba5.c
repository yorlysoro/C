#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char cadena[50];
	char palabras[3][50] = { "comer", "hola\n", "adios" };
	int tamcadint = 0;
	int i;
	int igual;
	//char cadena2[1][10] = { "comer"} ;
	char cadena3[50];
	//char c;
	fgets(cadena,50,stdin);
	tamcadint = strlen(cadena);
	//for(i = 0; i < tamcadint; i++)
	//{
		//printf("%c ", cadena[i]);
	//}
	
	//igual = strcmp(palabras[2],cadena2[0]);
	//printf("%c ", palabras[0][1]);
	//printf("%d ", igual);
	for(i = 0; i < tamcadint; i++)
	{	
		if(cadena != '\0')
		{
			    cadena3[i] = cadena[i];
		}
	}
	
	printf("%s ", cadena3);
	igual = strcmp(cadena3, palabras[1]);
	printf("%d \n", igual);
	if(igual == 0)
	{
		printf("%s \n", cadena3);
	}
	int blank;
	for(i = 0; i < tamcadint; i++)
	{
		blank = isblank(cadena[i]);
		//printf("%d \n", blank);
		if(blank != 0)
		{
			printf("%s\n", cadena);
		}
	}
	
	return 0;
}
