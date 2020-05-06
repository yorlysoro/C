#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define PILA_TAMANIO 5
#define LN putchar('\n');

typedef struct
{
	int iPilaTope;
	int arrIntPila[PILA_TAMANIO];
}pila;

void SbPilaInicializa(pila *pPila)
{
	pPila->iPilaTope=-1;
	printf("Pila inicializada\n");
}


int FnIntPilaVacia(pila *pPila)
{
	if(pPila->iPilaTope==-1)
	return TRUE;
	else
	return FALSE;
}

int FnIntPilaLLena(pila *pPila)
{
	if(pPila->iPilaTope==PILA_TAMANIO-1)
	return TRUE;
	else
	return FALSE;
}

int FnIntPilaELementos(pila *pPila)
{
	return pPila->iPilaTope+1;
}

void SbPilaCima(pila *pPila)
{
	if(FnIntPilaVacia(pPila))
	printf("La pila esta vacia; no ha elemento en la cima\n");
	else
	printf("Pila Cima: %d", pPila->arrIntPila[pPila->iPilaTope]);
}
void SbPilaPush(pila *pPila, int iElemento)
{
	if(FnIntPilaLLena(pPila))
	printf("La pila esta llena y no es posible agregar el elemento: %d\n", iElemento);
	else
	{
		pPila->iPilaTope++;
		pPila->arrIntPila[pPila->iPilaTope] = iElemento;
		printf("Se ha agregado el elemento: %d a la pila \n", iElemento);
	}
}

int FnIntPilaPop(pila *pPila)
{
	if(FnIntPilaVacia(pPila))
	{
		printf("La pila esta vacia no es posible sacar elementos\n");
		return pPila->iPilaTope;
	}
	else
	{
		printf("Se ha sacado un elemento de la pila\n");
		return(pPila->arrIntPila[pPila->iPilaTope--]);
	}
}
int main(void)
{
	pila xPila;
	int iElemento;
	
	SbPilaInicializa(&xPila);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	
	
	SbPilaCima(&xPila);
	LN
	
	SbPilaPush(&xPila,34);
	SbPilaPush(&xPila,25);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	LN
	
	iElemento = 12;
	SbPilaPush(&xPila,iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	LN
	
	iElemento = 14;
	SbPilaPush(&xPila, iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	LN
	
	iElemento = 13;
	SbPilaPush(&xPila, iElemento);
	SbPilaPush(&xPila, 8);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	SbPilaCima(&xPila);
	LN
	LN
	
	iElemento = FnIntPilaPop(&xPila);
	printf("El elemento sacado de la pila es %d\n", iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	SbPilaCima(&xPila);
	LN
	LN
	
	iElemento = FnIntPilaPop(&xPila);
	printf("El elemento sacado de la pila es %d\n", iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	SbPilaCima(&xPila);
	LN
	LN
	
	iElemento = FnIntPilaPop(&xPila);
	printf("El elemento sacado de la pila es %d\n", iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	SbPilaCima(&xPila);
	LN
	LN
	
	iElemento = FnIntPilaPop(&xPila);
	printf("El elemento sacado de la pila es %d\n", iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	SbPilaCima(&xPila);
	LN
	LN
	
	iElemento = FnIntPilaPop(&xPila);
	printf("El elemento sacado de la pila es %d\n", iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	SbPilaCima(&xPila);
	LN
	LN
	
	iElemento = FnIntPilaPop(&xPila);
	printf("El elemento sacado de la pila es %d\n", iElemento);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLLena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaELementos(&xPila));
	SbPilaCima(&xPila);
	LN
	LN
	return 0;
}
