/*
 * Listas_Enlazadas.h
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#ifndef LISTAS_ENLAZADAS_H_
#define LISTAS_ENLAZADAS_H_
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>

struct stcNodo
{
	int iDato;
	struct stcNodo *pSiguiente;
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

void SbListaInsertar(nodo **pCabeza, int xDato)
{
	nodo *pNodoNuevo;

	pNodoNuevo = FnNodoCrea(xDato);

	if(FnIntListaVacia(*pCabeza))
	{
		*pCabeza = pNodoNuevo;
		printf("Se ha insertado el elemento %d como primero en a lista\n\n", xDato);
	}
	else
	{
		pNodoNuevo->pSiguiente = *pCabeza;
		*pCabeza = pNodoNuevo;
		printf("Se ha insertado el elemento %d en el frente de la lista\n\n", xDato);
	}
}

nodo FnNodoListaElimina(nodo **pCabeza)
{
	nodo xNodo;
	nodo *pNodoEliminar;

	xNodo.iDato=-1;
	xNodo.pSiguiente=NULL;

	if(FnIntListaVacia(*pCabeza))
		printf("La lista esta vacia no hay elementos para eliminar\n\n");
	else
	{
		pNodoEliminar = *pCabeza;
		xNodo.iDato = pNodoEliminar->iDato;
		xNodo.pSiguiente = pNodoEliminar->pSiguiente;

		free(pNodoEliminar);

		printf("Se elimino el elemento:%d en la direccion:%p que apuntaba a direccion:%p\n\n", xNodo.iDato, pNodoEliminar, xNodo.pSiguiente);
		//*pCabeza = (*pCabeza)->pSiguiente;
		*pCabeza = xNodo.pSiguiente;
	}
	return (xNodo);
}

void SbListaDespliega(nodo *pCabeza)
{
	char iContar = 0;

	printf("Desplegando los elementos de la lista\n");

	while(pCabeza != NULL)
	{
		printf("Elemento:%d Valor:%d en direccion:%p que apunta a:%p\n", ++iContar,pCabeza->iDato,pCabeza,pCabeza->pSiguiente);
		pCabeza = pCabeza->pSiguiente;
	}
	putchar('\n');
}

int FnIntListaBuscaNodo(nodo *pCabeza, int xDato)
{
	char iContar=0;
	int iResult = FALSE;

	printf("Bunscando Elemento en la lista\n");
	while(pCabeza!=NULL)
	{
		iContar++;
		if(pCabeza->iDato==xDato)
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
		printf("El elemento no fue encontrado\n", iContar);

	putchar('\n');
}
#endif /* LISTAS_ENLAZADAS_H_ */
