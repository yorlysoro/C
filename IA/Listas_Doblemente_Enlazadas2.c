/*
 * Listas_Doblemente_Enlazadas2.c
 * 
 * Copyright 2016 copyleft <copyleft@debian>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct stcNodo
{
	int iDato;
	struct stcNodo *pSiguiente;
	struct stcNodo *pAnterior;
};

typedef struct stcNodo nodo;

int FnIntListaVacia(nodo *pCabeza)
{
	if(pCabeza==NULL)
	{
		printf("La lista esta vacia\n");
		return TRUE;
	}
	else
	{
		printf("La lista no esta vacia\n");
		return FALSE;
	}
}

nodo *FnNodoCrea(int xDato)
{
	nodo *xNodo;
	xNodo = (nodo *)malloc(sizeof(nodo));

	if(xNodo == NULL )
		printf("Error, No se puede reservar memoria para el nodo");

	else
	{
		xNodo->iDato = xDato;
		xNodo->pSiguiente = NULL;
	}
	return xNodo;
}

void SbListaDobleInsertarFinal(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo *pNodoNuevo;
	
	pNodoNuevo = FnNodoCrea(xDato);
	
	if(FnIntListaVacia(*pCabeza))
	{
		pNodoNuevo->pSiguiente = NULL;
		pNodoNuevo->pAnterior = NULL;
		
		*pCabeza = pNodoNuevo;
		*pCola = pNodoNuevo;
		
		printf("Insercion lista doblemente enlazada vacia, Elemento:%d en direccion:%p\n", xDato, pNodoNuevo);
	}
	else
	{
		pNodoNuevo->pSiguiente = NULL;
		pNodoNuevo->pAnterior = *pCola;
		
		(*pCola)->pSiguiente = pNodoNuevo;
		
		*pCola = pNodoNuevo;
		
		printf("Insercion Final Lista Doblemente Enlazada, Elemento:%d en direccion:%p\n", xDato, pNodoNuevo);
	}
}


nodo FnNodoListaDobleEliminaFinal(nodo **pCabeza, nodo **pCola)
{
	nodo xNodo;
	
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	xNodo.pAnterior = NULL;
	
	if(FnIntListaVacia(*pCabeza))
	{
		puts("La lista esta vacia");
	}
	else
	{
		xNodo.iDato = (*pCola)->iDato;
		xNodo.pSiguiente = (*pCola)->pSiguiente;
		xNodo.pAnterior = (*pCola)->pAnterior;
		
		if(*pCola == *pCabeza)
		{
			free(*pCabeza);
			*pCabeza = NULL;
			*pCola = NULL;
		}
		else
		{
			free(*pCola);
			*pCola=(*pCola)->pAnterior;
			(*pCola)->pSiguiente = NULL;
		}
		printf("Eliminacion Final Lista Doblemente Enlazada; Elemento:%d en direccion:%p\n", xNodo.iDato, xNodo.pSiguiente);
	}
	return (xNodo);
}

void SbListaDobleDespliegaFull(nodo *pCabeza, nodo *pCola, int iOrdenNormal)
{
	char iContar = 0;
	
	if(FnIntListaVacia(pCabeza))
	{
		puts("La lista doblement enlzada se encuentra vacia");
	}
	else
	{
		puts("Desplegando los elementos de la lista");
		if(iOrdenNormal)
		{
			puts("En orden normal");
			while(pCabeza!=NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n", ++iContar, pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCabeza = pCabeza->pSiguiente;
			}
		}
		else
		{
			puts("En orden inverso");
			while(pCola!=NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n", ++iContar, pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCola = pCola->pAnterior;
			}
		}
	}
	putchar('\n');
}

int main(int argc, char **argv)
{
	nodo *pCabeza = NULL;
	nodo *pCola = NULL;

	nodo xNodo;

	SbListaDobleInsertarFinal(&pCabeza,&pCola,10);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,20);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,30);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,40);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,50);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleDespliegaFull(pCabeza,pCola,FALSE);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleDespliegaFull(pCabeza,pCola,FALSE);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);


	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,99);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,98);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,97);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,96);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	printf("Accediendo todos los Nodos desde Cabeza\n");

	printf("%d\n", pCabeza->iDato);
	printf("%d\n", pCabeza->pSiguiente->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->pAnterior->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->pAnterior->pAnterior->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->pAnterior->pAnterior->pAnterior->iDato);
	return 0;
}

