/*
 * Listas_Enlazadas.c
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
#define TRUE 1
#define FALSE 0
#include <stdlib.h>

struct stcNodo{
	int iDato;
	struct stcNodo *pSiguiente;
};

typedef struct stcNodo nodo;

int FnIntListaVacia(nodo *pCabeza)
{
	if(pCabeza == NULL)
	{
		puts("La lista esta vacia");
		return TRUE;
	}
	else
	{
		puts("La lista no esta vacia");
		return FALSE;
	}
}

nodo *FnNodoCrea(int xDato)
{
	nodo *xNodo;
	xNodo = (nodo *)malloc(sizeof(nodo));
	
	if(xNodo == NULL)
		perror("xNodo, no se pudo reservar memoria para el nodo");
	else
	{
		xNodo->iDato = xDato;
		xNodo->pSiguiente = NULL;
	}
	return xNodo;
}

void SbListaInsertar(nodo **pCabeza, int xDato)
{
	nodo *pNodoNuevo;
	pNodoNuevo = FnNodoCrea(xDato);
	
	if(FnIntListaVacia(*pCabeza))
	{
		*pCabeza = pNodoNuevo;
		printf("Se ha insertado el dato %d como primero en la list\n", xDato);
	}
	else
	{
		pNodoNuevo->pSiguiente = *pCabeza;
		*pCabeza = pNodoNuevo;
		printf("Se ha insertado el dato %d en el frente de la lista\n", xDato);
	}
}

nodo FnNodoListaElimina(nodo **pCabeza)
{
	nodo xNodo;
	nodo *pNodoEliminar;
	
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	
	if(FnIntListaVacia(*pCabeza))
		puts("La lista esta vacia no se pueden eliminar elementos");
	else
	{
		pNodoEliminar = *pCabeza;
		xNodo.iDato = pNodoEliminar->iDato;
		xNodo.pSiguiente = pNodoEliminar->pSiguiente;
		
		free(pNodoEliminar);
		
		printf("Se elemino el dato:%d en la direccion:%p que apuntaba a direccion:%p\n", xNodo.iDato, pNodoEliminar, xNodo.pSiguiente);
		
		*pCabeza = xNodo.pSiguiente;
	}
	return (xNodo);
}

void SbListaDespliega(nodo *pCabeza)
{
	char iContar = 0;
	
	puts("Desplegando los elementos de la lista");
	
	while(pCabeza != NULL)
	{
		printf("Dato:%d Valor:%d en direccion:%p que apunta a:%p\n", ++iContar,pCabeza->iDato, pCabeza, pCabeza->pSiguiente);
		pCabeza = pCabeza->pSiguiente;
	}
	putchar('\n');
}

int FnIntListaBuscaNodo(nodo *pCabeza, int xDato)
{
	char iContar = 0;
	int iResult = FALSE;
	
	puts("Buscando el elemento en la lista");
	
	while(pCabeza != NULL)
	{
		iContar++;
		if(pCabeza->iDato == xDato)
		{
			iResult = TRUE;
			break;
		}
		else
			pCabeza = pCabeza->pSiguiente;
	}
	if(iResult)
		printf("El elemento fue encontrado en la posicion:%d\n", iContar);
	else
		puts("No se pudo encontrar el elemento");
		
	putchar('\n');
	return (iResult);
}

int main(int argc, char **argv)
{
	nodo xNodo;
	nodo *pCabeza = NULL;
	printf("El tamaño en bytes de pCabeza:%zd \n\n", sizeof(pCabeza));

	SbListaInsertar(&pCabeza,20);
	SbListaDespliega(pCabeza);

	xNodo = FnNodoListaElimina(&pCabeza);

	SbListaDespliega(pCabeza);

	SbListaInsertar(&pCabeza,25);
	SbListaDespliega(pCabeza);

	SbListaInsertar(&pCabeza,27);
	SbListaInsertar(&pCabeza,72);

	SbListaDespliega(pCabeza);

	FnIntListaBuscaNodo(pCabeza,72);
	return 0;
}

