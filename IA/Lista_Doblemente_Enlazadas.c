/*
 * Lista_Doblemente_Enlazadas.c
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
		perror("xNodo: No se puede reservar memoria para el nodo");
	else
	{
		xNodo->iDato = xDato;
		xNodo->pSiguiente = NULL;
	}
	return (xNodo);
}

void SbListaDobleInsertarFrente(nodo **pCabeza, int xDato)
{
	nodo *pNodoNuevo;
	
	pNodoNuevo = FnNodoCrea(xDato);
	if(FnIntListaVacia(*pCabeza))
	{
		pNodoNuevo->pSiguiente = NULL;
		pNodoNuevo->pAnterior = NULL;
		
		*pCabeza = pNodoNuevo;
		
		printf("Se ha insertado el elemento:%d en direccion:%p\n", xDato, pNodoNuevo);
	}
	else
	{
		(*pCabeza)->pAnterior = pNodoNuevo;
		pNodoNuevo->pSiguiente = *pCabeza;
		pNodoNuevo->pAnterior = NULL;
		*pCabeza = pNodoNuevo;
		
		printf("Se ha insertado el elemento:%d en direccion:%p\n", xDato, pNodoNuevo);
	}
}

nodo FnNodoListaDobleEliminarFrente(nodo **pCabeza)
{
	nodo xNodo;
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	xNodo.pAnterior = NULL;
	
	if(FnIntListaVacia(*pCabeza))
	{
		puts("La lista esta vacia\n");
	}
	else
	{
		xNodo.iDato = (*pCabeza)->iDato;
		xNodo.pSiguiente = (*pCabeza)->pSiguiente;
		xNodo.pAnterior = (*pCabeza)->pAnterior;
		
		free(*pCabeza);
		
		*pCabeza = (*pCabeza)->pSiguiente;
		
		if(*pCabeza != NULL)
			(*pCabeza)->pAnterior = NULL;
		printf("Eliminacion frente lista doblemente enlazada elemento:%d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
	}
	return (xNodo);
}
void SbListaDobleDespliega(nodo *pCabeza, int iOrdenNormal)
{
	char iContar = 0;
	
	if(FnIntListaVacia(pCabeza))
		puts("La lista esta vacia");
	else
	{
		puts("Desplegando los elementos de la lista...");
		if(iOrdenNormal)
		{
			puts("En orden Normal");
			while(pCabeza != NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n", ++iContar, pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCabeza=pCabeza->pSiguiente;
			}
		}
		else
		{
			puts("En orden inverso");
			while(pCabeza->pSiguiente != NULL)
			{
				pCabeza = pCabeza->pSiguiente;
				iContar++;
			}
			iContar++;
			while(pCabeza != NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n",++iContar, pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCabeza = pCabeza->pAnterior;
			}
		}
	}
}

int main(int argc, char **argv)
{
	nodo *pCabeza = NULL;

	nodo xNodo;

	SbListaDobleInsertarFrente(&pCabeza,10);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);
	
	SbListaDobleInsertarFrente(&pCabeza,19);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);

	SbListaDobleInsertarFrente(&pCabeza,13);
	SbListaDobleInsertarFrente(&pCabeza,14);
	SbListaDobleInsertarFrente(&pCabeza,27);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);
	
	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleInsertarFrente(&pCabeza,99);

	SbListaDobleDespliega(pCabeza,TRUE);
	return 0;
}

