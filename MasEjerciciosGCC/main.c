#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
typedef struct calculadora {
	char numero1[TAM], numero2[TAM], accion[TAM];

}calc;
char verificar_str(char num1[TAM], char num2[TAM], char acc[TAM]);

int main(void)
{
	calc xcalculadora[5];
	int i; static char result[TAM];
	puts("Una calculador sencilla");
	for(i = 0; i < 5; i++)
	{
		puts("Introduzca el primero numero");
		fgets(xcalculadora[i].numero1,TAM-1,stdin);
		puts("Introduzca el segundo numero");
		fgets(xcalculadora[i].numero2,TAM-1,stdin);
		puts("Indique que accion: Solo disponible suma, resta, multiplicacion o division");
		puts("Puede introducir la accion en palabra o simbolos + - * /");
		fgets(xcalculadora[i].accion,TAM-1,stdin);
		result[TAM] = verificar_str(xcalculadora[i].numero1, xcalculadora[i].numero2, xcalculadora[i].accion);
		printf("El resultado es %s\n", result);
	}
	return 0;


}

char verificar_str(char num1[TAM], char num2[TAM], char acc[TAM])
{
	int i, nume1[TAM], nume2[TAM], result[TAM];
	static char result2[TAM];
	for(i = 0; i < TAM; i++)
	{
		if(num1 != '\0' && num2 != '\0')
		{
			if(isdigit(num1[i]) != 0 )
			{
				nume1[i] = (int)num1[i];
			}
			else if(isdigit(num2[i]) != 0)
			{
				nume2[i] = (int)num2[i];
			}
		}
	}
	for(i = 0; i < TAM; i++)
	{
		if(acc[i] != '\0')
		{
			if(isalpha(acc[i]) != 0)
			{
				if(isupper(acc[i]) != 0)
				{
					acc += 32;
				}
			}
		}
	}

	if(*acc == '+' || strcmp(acc,"suma") == 0)
	{
		*result = *nume1 + *nume2;
	}
	else if(*acc == '-' || strcmp(acc, "resta") == 0)
	{
		*result = *nume1 - *nume2;
	}
	else if(*acc =='*' || strcmp(acc, "multiplicacion") == 0)
	{
		*result = *nume1 * *nume2;
	}
	else if(*acc == '/' || strcmp(acc, "division\n") == 0)
	{
		*result = *nume1 / *nume2;
	}
	*result2 = (char)*result;
	return *result2;
}

