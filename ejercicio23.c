#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char texto[4];
	char ntext[10], ntext1[10];
	int num;
	float total;
	
	printf("Numeroa de 3 digitos: ");
	scanf("%i", &num);
	fflush(stdin);
	printf("Cadena numerica: ");
	gets(ntext);
	fflush(stdin);
	printf("Cadena numerica: ");
	gets(ntext1);
	fflush(stdin);
	
	sprintf(texto, "%d", num);
	printf("%c %c %c\n", texto[0], texto[1], texto[2]);
	
	total=atof(ntext)+atof(ntext1);
	printf("%.3f", total);
	return 0;
}
