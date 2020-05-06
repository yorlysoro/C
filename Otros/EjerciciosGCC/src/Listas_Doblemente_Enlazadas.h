/*
 * Listas_Doblemente_Enlazadas.h
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#ifndef LISTAS_DOBLEMENTE_ENLAZADAS_H_
#define LISTAS_DOBLEMENTE_ENLAZADAS_H_
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>
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
void SbListaDobleInsertarFrente(nodo **pCabeza, int xDato)
{
	nodo *pNodoNuevo;

	pNodoNuevo=FnNodoCrea(xDato);
	if(FnIntListaVacia(*pCabeza))
	{
		pNodoNuevo->pSiguiente = NULL;
		pNodoNuevo->pAnterior = NULL;

		*pCabeza = pNodoNuevo;

		printf("Insercion Lista Doblemente Enlazada Vacia: Elemento:%d en direccion:%p\n", xDato, pNodoNuevo);
	}
	else
	{
		(*pCabeza)->pAnterior = pNodoNuevo;

		pNodoNuevo->pSiguiente = *pCabeza;

		pNodoNuevo->pAnterior = NULL;

		*pCabeza = pNodoNuevo;

		printf("Insercion Inicio Lista Doblemente Enlazada: Elemento:%d en direccion:%p\n", xDato, pNodoNuevo);


	}
}

nodo FnNodoListaDobleEliminarFrente(nodo **pCabeza)
{
	nodo xNodo;

	xNodo.iDato=-1;
	xNodo.pSiguiente=NULL;
	xNodo.pAnterior=NULL;

	if(FnIntListaVacia(*pCabeza))
	{
		printf("La lista Doblemente enlazada esta vacia\n\n");
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
		printf("Eliminancion Frente lista doblemente enlazada Elemente:%d SIgte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
	}
	return (xNodo);
}


void SbListaDobleDespliega(nodo *pCabeza, int iOrdenNormal)
{
	char iContar=0;

	if(FnIntListaVacia(pCabeza))
	{
		printf("La lista doblemente enlazada esta vacia\n");
	}
	else
	{
		printf("Desplegando los elementos de la lista\n");
		if(iOrdenNormal)
		{
			printf("En orden normal\n");
			while(pCabeza!=NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n", ++iContar,pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCabeza=pCabeza->pSiguiente;
			}
		}
		else
		{
			printf("En orden inverso\n");

			while(pCabeza->pSiguiente!=NULL)
			{
				pCabeza=pCabeza->pSiguiente;
				iContar++;
			}
			iContar++;

			while(pCabeza!=NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n", ++iContar,pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCabeza = pCabeza->pAnterior;
			}
		}
	}
}
#endif /* LISTAS_DOBLEMENTE_ENLAZADAS_H_ */
