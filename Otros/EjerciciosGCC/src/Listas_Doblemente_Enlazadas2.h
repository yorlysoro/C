/*
 * Listas_Doblemente_Enlazadas2.h
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#ifndef LISTAS_DOBLEMENTE_ENLAZADAS2_H_
#define LISTAS_DOBLEMENTE_ENLAZADAS2_H_
#include "Listas_Doblemente_Enlazadas.h"

void SbListaDobleInsertarFinal(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo *pNodoNuevo;

	pNodoNuevo = FnNodoCrea(xDato);

	if(FnIntListaVacia(*pCabeza))
	{
		pNodoNuevo->pSiguiente=NULL;
		pNodoNuevo->pAnterior=NULL;

		*pCabeza=pNodoNuevo;
		*pCola=pNodoNuevo;

		printf("Insercion Lista Doblemente Enlazada Vacia; Elemento %d en direccion %p\n", xDato, pNodoNuevo);
	}
	else
	{
		pNodoNuevo->pSiguiente = NULL;
		pNodoNuevo->pAnterior = *pCola;


		(*pCola)->pSiguiente = pNodoNuevo;

		*pCola = pNodoNuevo;
		printf("Insercion Final Lista Doblemente Enlazada; Elemento %d en direccion %p\n", xDato, pNodoNuevo);
	}
}

nodo FnNodoListaDobleEliminaFinal(nodo **pCabeza, nodo **pCola)
{
	nodo xNodo;

	xNodo.iDato=-1;
	xNodo.pSiguiente=NULL;
	xNodo.pAnterior=NULL;

	if(FnIntListaVacia(*pCabeza))
	{
		printf("La lista doblemenete enlazada esta vacia\n");
	}
	else
	{
		xNodo.iDato = (*pCola)->iDato;
		xNodo.pSiguiente = (*pCola)->pSiguiente;
		xNodo.pAnterior = (*pCola)->pAnterior;

		if(*pCola==*pCabeza)
		{
			free(*pCabeza);

			*pCabeza=NULL;
			*pCola=NULL;
		}
		else
		{
			free(*pCola);
			*pCola=(*pCola)->pAnterior;
			(*pCola)->pSiguiente = NULL;
		}
		printf("Eliminacion Final Lista Doblemente Enlazada; Elemento %d en direccion %p\n", xNodo.iDato, xNodo.pSiguiente);
	}
	return (xNodo);
}

void SbListaDobleDespliegaFull(nodo *pCabeza, nodo *pCola, int iOrdenNormal)
{
	char iContar = 0;

	if(FnIntListaVacia(pCabeza))
	{
		printf("La lista doblemente enlazada se encuentra vacia\n\n");
	}
	else
	{
		printf("Desplegando los elementos de la lista\n");

		if(iOrdenNormal)
		{
			printf("En orden normal\n");
			while(pCabeza!=NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n", ++iContar, pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCabeza = pCabeza->pSiguiente;
			}
		}
		else
		{
			printf("En orden normal\n");
			while(pCola!=NULL)
			{
				printf("Elemento:%d Valor:%d en direccion:%p pSigte:%p pAnter:%p\n", ++iContar, pCabeza->iDato, pCabeza, pCabeza->pSiguiente, pCabeza->pAnterior);
				pCola = pCola->pAnterior;
			}
		}
	}
	putchar('\n');
}

#endif /* LISTAS_DOBLEMENTE_ENLAZADAS2_H_ */
