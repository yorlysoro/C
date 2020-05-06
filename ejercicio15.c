#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char letra;
	
	printf("Introducir valor: ");
	letra = getchar();
	
	if(isdigit(letra))
	printf("Es un nuemro");
	
	else
	{
		if(islower(letra))
		printf("Letra en minuscula");
		else
		printf("Letra en mayuscula");
		if(ispunct(letra))
		printf("Caracter de puntuacion");
		if(!isgraph(letra))
		printf("Es un espacio");
	}
	return 0;
}
