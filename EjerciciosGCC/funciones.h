//#include "dinamo.c"
//#include "ejecutar.h"
//#include "actualizar.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 100
void inicio(void);
char a_minusculas(char minusculas[TAM]);
void verificar(char verificar[TAM]);
void navegador_fun(void);
void terminal_fun(void);
void calendario_fun(void);

void inicio(void)
{
	static char entrada[TAM];
	char verificar1[TAM];
	int i;
	fgets(entrada,TAM-1,stdin);
	entrada[TAM] = a_minusculas(entrada);
	for(i = 0; i < TAM; i++)
	{
		if(entrada[i] != '\0')
		{
		  verificar1[i] = entrada[i];
		}
	}
	verificar(verificar1);
		
}

char a_minusculas(char minusculas[TAM])
{
	int cont;
	for(cont = 0; cont < TAM; cont++)
	{
		if(isupper(minusculas[cont]) != 0 && minusculas[cont] != '\0')
		{
			minusculas[cont] += 32;
		}

	}
	return minusculas[TAM];
}
void verificar(char verificar[TAM])
{
	unsigned int i, num;
	char navegador[TAM] = "navegador\n",
		 terminal[TAM] = "terminal\n",
		 calendario[TAM] = "calendario\n",
		 salir[TAM][TAM] = {"chao\n", "hasta luego\n", "adios\n", "salir\n", "hasta mañana\n", "me voy\n", "me despido\n", "nos vemos\n"},
		 agregar[TAM][TAM] = { "agregar", "agrega", "nuevos programas", "nuevo programa"},
		 ver[TAM][TAM] = { "ver programas", "mostrar programas", "guardados", "ver guardados", "ver programas guardados", "mostrar programas guardados"},
		 abrir[TAM][TAM] = { "ejecutar", "abrir programas", "abrir programa" },
		 actualizar[TAM][TAM] = {"actualizar", "actualizar sistema", "actualizar programa"},
		 instalar[TAM][TAM] = { "instalar", "instalar programa", "instalar programas"};
	if(strcmp(verificar, navegador) == 0)
	{
		navegador_fun();
	}
	else if(strcmp(verificar,terminal) == 0)
	{
		terminal_fun();
	}
	else if(strcmp(verificar,calendario) == 0)
	{
		calendario_fun();
	}
	else
	{
		for(i = 0; i < TAM; i++)
		{
			if(strcmp(verificar, salir[i]) == 0)
			{
				srand(time(NULL));
				num = 2 + (rand() % 3);
				if((num-2) == 0)
				{
					puts("Adios");
				}
				else if((num-2) == 1)
				{
					puts("Hasta luego");
				}
				else if((num-2) == 2)
				{
					puts("chao");
				}
			}
		}
	}
	
}
void navegador_fun(void)
{
	int opciones;
	puts("Elija una opcion");
	puts("1)Firefox\n2)Chromium\n3)Midori\n4)Salir");
	scanf("%d", &opciones);
	switch(opciones)
	{
		case 1:
		system("firefox &");
		break;
		case 2:
		system("chromium &");
		break;
		case 3:
		system("midori &");
		break;
		case 4:
		exit(1);
		default:
		fputs("Opcion Invalida", stderr);
	}
}
void terminal_fun(void)
{
	int opciones = 0;
	puts("Elija una opcion");
	puts("1)Bash\n2)Sh\n3)salir");
	switch(opciones)
	{
		case 1:
		system("bash");
		break;
		case 2:
		system("sh");
		break;
		case 3:
		exit(2);
		default:
		fputs("Opcion Invalida",stderr);
	}
	
}
void calendario_fun(void)
{
	system("cal");
}
