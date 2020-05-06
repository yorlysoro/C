#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio_Pila.h"
void menu(void);
void verifica_palindromo(void);
void mostrar_al_reves(void);
void operaciones_matematicas(void);
int main(void)
{
	menu();
	return 0;
}

void menu(void)
{
	char ch[2];
	int ich;
	
	puts("a)Verificar si la palabra es palindromo"
	"\nb)Mostrar una palabra al reves"
	"\nc)Realiza operaciones matematicas"
	"\nq)Salir");
	fgets(ch,3,stdin);
	ich = (int)ch[0];
	switch(ich)
	{
		case 97:
		verifica_palindromo();
		break;
		case 98:
		mostrar_al_reves();
		break;
		case 99:
		operaciones_matematicas();
		break;
		case 113:
		puts("Adios");
		exit(1);
		default:
	    puts("¡Caracter no reconocido!");
	    exit(2);
	}
		
		
}

void verifica_palindromo(void)
{
	char palabra[30];
	char *ppalabra;
	int palindromo;
	puts("Introduca la palabra que quieres verificar");
	fgets(palabra,30,stdin);
	ppalabra = strchr(palabra,10);
	if(ppalabra != NULL)
	{
		*ppalabra = '\0';
	}
	palindromo = FnIntPalindromo(palabra);
	if(palindromo == TRUE)
	puts("La palabra es un palindromo");
	else
	puts("La palabra no es un palindromo");
	
	return;
}
void mostrar_al_reves(void)
{
	char palabra[30];
	char *ppalabra;
	char *alreves;
	puts("Introduzca la palabra que quiere ver al reverso");
	fgets(palabra,30,stdin);
	ppalabra = strchr(palabra,10);
	if(ppalabra != NULL)
	{
		*ppalabra = '\0';
	}
	alreves = FnStrInverso(palabra);
	printf("Esta es la palabra al reves: %s\n", alreves);
}
void operaciones_matematicas(void)
{
	int result;
	char cadena[30];
	char *pcadena;
	puts("Introduzca una expresion matematica");
	fgets(cadena,30,stdin);
	pcadena = strchr(cadena,10);
	if(pcadena != NULL)
	{
		*pcadena = '\0';
	}
	result = FnIntExpresionEvalua(cadena);
	if(result != -1)
	{
		printf("El resultado de la expresion es %d\n", result);
	}
	else
	{
		printf("Esta es expresion no es correcta: %s\n", cadena);
	}
	
}
