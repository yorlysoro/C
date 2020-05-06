/*
 * Listas_Circulares.h
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#ifndef LISTAS_CIRCULARES_H_
#define LISTAS_CIRCULARES_H_
#include "Listas_Enlazadas.h"

void SbListaCircularInsertar(nodo **pCola, int xDato)
{
	nodo *pNodoNuevo;

	pNodoNuevo=FnNodoCrea(xDato);

	if(FnIntListaVacia(*pCola))
	{
		pNodoNuevo->pSiguiente = pNodoNuevo;

		*pCola=pNodoNuevo;
		printf("Insercion al final con lista circular vacia, el elemento %d en direccion %p\n", xDato, pNodoNuevo);
	}
	else
	{
		pNodoNuevo->pSiguiente = (*pCola)->pSiguiente;

		(*pCola)->pSiguiente = pNodoNuevo;

		*pCola=pNodoNuevo;
		printf("Insercion al final con lista circular vacia, el elemento %d en direccion %p\n", xDato, pNodoNuevo);

	}
}

nodo FnNodoListaCircularElimina(nodo **pCola)
{
	nodo *pAux;
	nodo xNodo;

	xNodo.iDato=-1;
	xNodo.pSiguiente=NULL;

	if(FnIntListaVacia(*pCola))
	{
		printf("La lista circular esta vacia\nn");
	}
	else
	{
		if(*pCola == (*pCola)->pSiguiente)
		{
			xNodo.iDato = (*pCola)->iDato;
			xNodo.pSiguiente = (*pCola)->pSiguiente;

			free(*pCola);
			*pCola = NULL;

			printf("Eliminacion del unico elemento de la fila circular:%d que apuntaba:%p\n", xNodo.iDato, xNodo.pSiguiente);
		}
		else
		{
			pAux = (*pCola)->pSiguiente;

			xNodo.iDato = pAux->iDato;
			xNodo.pSiguiente = pAux->pSiguiente;

			(*pCola)->pSiguiente = pAux->pSiguiente;

			free(pAux);

			printf("Eliminacion del Frente de la cola circular: %d que apuntaba a:%p\n\n",xNodo.iDato, xNodo.pSiguiente );
		}
	}
	return (xNodo);
}

void SbListaCircularDespliega(nodo *pCola)
{
	char iContar = 0;
	nodo *pAuxiliar;

	if(FnIntListaVacia(pCola))
	{
		printf("La lista circular se encuentra vacia\n\n");
	}
	else
	{
		pAuxiliar = pCola->pSiguiente;

		printf("Desplegando los elementos de la lista...\n");

		while(pCola!=pAuxiliar)
		{
			printf("Elemento:%d Valor:%d en direccion:%p que apunta:%p\n", ++iContar, pAuxiliar->iDato, pAuxiliar, pAuxiliar->pSiguiente);
			pAuxiliar = pAuxiliar->pSiguiente;
		}
		printf("Elemento:%d Valor:%d en direccion:%p que apunta:%p\n", ++iContar, pAuxiliar->iDato, pAuxiliar, pAuxiliar->pSiguiente);

	}
	putchar('\n');
}

void SbListaCircularInicializa(nodo **pCola)
{
	nodo *pAuxiliar;

	if(FnIntListaVacia(*pCola))
	{
		printf("La lista circular esta vacia, no hay valores que desplegar\n");
	}
	else
	{
		pAuxiliar = (*pCola)->pSiguiente;
		printf("Eliminando los elementos de la lista circular\n");
		while(*pCola!=pAuxiliar)
		{
			free(pAuxiliar);
			pAuxiliar = pAuxiliar->pSiguiente;
		}
		free(*pCola);
		*pCola=NULL;
	}
	printf("Todos los elementos de la lista circular fueron eliminados");
}
#endif /* LISTAS_CIRCULARES_H_ */
