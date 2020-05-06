#include <stdio.h>
#include <stdlib.h>

void guarda(int i);
int recupera(void);
int *top, *p1, pila[50];

int main(void)
{
	int valor;
	top = pila;
	p1 = pila;
	
	do{
		printf("Introducir un valor: ");
			scanf("%i", &valor);
			if(valor != 0)
			guarda(valor);
			else
			printf("En lo alto: %d\n", recupera());
		}while(valor != 1);
	return 0;
}

void guarda(int i)
{
	p1++;
	if(p1 == (top+50))
	{
		printf("pila desbordada");
		exit(1);
	}
	*p1=i;
}

int recupera(void)
{
	if(p1 == top)
	{
		printf("Pila vacia");
		exit(1);
	}
	p1--;
	return *(p1+1);
}
