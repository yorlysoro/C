#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct calculadora
{
	float suma, resta, multi, div;
}xcalculadora;

typedef struct entrada
{
	char num1[50], num2[50];
}xentrada;


int main(void)
{
	xentrada numero;
	strcpy(numero.num1, "10.5");
	strcpy(numero.num2, "2.5");
	
	printf("%s\n", numero.num1);
	
	xcalculadora xsuma;
	xsuma.suma = atof(numero.num1) + atof(numero.num2);
	xsuma.resta = atof(numero.num1) - atof(numero.num2);
	xsuma.multi = atof(numero.num1) * atof(numero.num2);
	xsuma.div = atof(numero.num1) / atof(numero.num2);
	printf("%.0f\n", xsuma.suma);
	printf("%.0f\n", xsuma.resta);
	printf("%.2f\n", xsuma.multi);
	printf("%.2f\n", xsuma.div);
	
	strcpy(numero.num1, (char)(xsuma.suma));
	
	return 0;
}
