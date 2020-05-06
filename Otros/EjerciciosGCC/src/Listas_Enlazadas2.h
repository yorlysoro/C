/*
 * Listas_Enlazadas2.h
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#ifndef LISTAS_ENLAZADAS2_H_
#define LISTAS_ENLAZADAS2_H_
//#include <stdio.h>
//#include <stdlib.h>
#include "Listas_Enlazadas.h"
//#define TRUE 1
//#define FALSE 0

//struct stcNodo
//{
//	int iDato;
//	struct stcNodo *pSiguiente;
//};
//
//typedef struct stcNodo nodo;


void SbListaInsertarFinal(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo *pNodoNuevo;
	nodo *pAux;

	pNodoNuevo=FnNodoCrea(xDato);

	if(FnIntListaVacia(*pCabeza))
	{
		*pCabeza=pNodoNuevo;
		*pCola=pNodoNuevo;
		printf("Se ha insertado el elemento %d en el frente estando la lista vacia\n", xDato);
	}
	else
	{
		pAux = *pCola;
		pAux->pSiguiente = pNodoNuevo;

		*pCola = pNodoNuevo;

		printf("Se ha insertado el elemento %d en el final de la lista\n", xDato);
	}
}

void SbListaInsertarDespues(nodo *pCabeza, nodo **pCola, int xDatoDespuesDe, int xDatoInsertar)
{
	nodo *pNodoNuevo;
	char iContar=0;
	char iResult=FALSE;

	printf("Buscando Elemento para insertar despues de el ...\n");

	while(pCabeza!=NULL)
	{
		iContar++;
		if(pCabeza->iDato==xDatoDespuesDe)
		{
			iResult=TRUE;
			pNodoNuevo=FnNodoCrea(xDatoInsertar);

			if(pCabeza == *pCola)
			{
				(*pCola)->pSiguiente = pNodoNuevo;

				*pCola = pNodoNuevo;
				printf("Se ha insertado el elemento %d en el final de la lista despues de %d\n ", xDatoInsertar, xDatoDespuesDe);
			}
			else
			{
				pNodoNuevo->pSiguiente = pCabeza->pSiguiente;
				pCabeza->pSiguiente=pNodoNuevo;
				printf("Se ha insertado el elemento:%d en la lista, despues de %d\n", xDatoInsertar, xDatoDespuesDe);
			}
			break;
		}
		else
			pCabeza = pCabeza->pSiguiente;
	}
	if(!iResult)
		printf("EL elemento a buscar %d para insertar despues, no fue encontrado\n", xDatoDespuesDe);
	putchar('\n');
}

nodo FnNodoListaEliminaFinal(nodo **pCabeza, nodo **pCola)
{
	nodo xNodo;
	nodo *pNodoAuxiliar;

	xNodo.iDato=-1;
	xNodo.pSiguiente=NULL;

	if(FnIntListaVacia(*pCabeza))
		printf("La lista esta vacia no hay elemenotos para eliminar\n");
	else
	{
		if(*pCabeza==*pCola)
		{
			pNodoAuxiliar = *pCabeza;

			xNodo.iDato = pNodoAuxiliar->iDato;
			xNodo.pSiguiente = pNodoAuxiliar->pSiguiente;

			free(pNodoAuxiliar);

			*pCola = NULL;
			*pCabeza = NULL;

			printf("Se ha eliminar del final el unica elemento que habia:%d en direccion:%p que apuntaba a:%p\n", xNodo.iDato, pNodoAuxiliar, xNodo.pSiguiente);
		}
		else
		{
			pNodoAuxiliar = *pCabeza;

			while(pNodoAuxiliar->pSiguiente!=*pCola)
			{
				pNodoAuxiliar=pNodoAuxiliar->pSiguiente;
			}
			//xNodo.iDato = pNodoAuxiliar->iDato;
			//xNodo.pSiguiente = pNodoAuxiliar->pSiguiente;
			xNodo.iDato = (*pCola)->iDato;
			xNodo.pSiguiente = (*pCola)->pSiguiente;
			free(*pCola);

			*pCola = pNodoAuxiliar;

			pNodoAuxiliar->pSiguiente=NULL;

			printf("Se ha eliminar del final elemento:%d en direccion:%p que apuntaba a:%p\n", xNodo.iDato, pNodoAuxiliar, xNodo.pSiguiente);

		}
	}
	return (xNodo);
}

nodo FnNodoListaEliminaDato(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo xNodo;
	nodo *pNodoAnterior = NULL;
	nodo *pNodoActual;
	nodo *pNodoEliminar;

	int iResult=FALSE;

	xNodo.iDato=-1;
	xNodo.pSiguiente=NULL;

	if(FnIntListaVacia(*pCabeza))
		printf("La lista esta vacia, no hay elementos para eliminar\n");
	else
	{
		pNodoActual = *pCabeza;

		while(pNodoActual != NULL)
		{
			if(pNodoActual->iDato==xDato)
			{
				pNodoEliminar = pNodoActual;
				xNodo.iDato = pNodoEliminar->iDato;
				xNodo.pSiguiente = pNodoEliminar->pSiguiente;

				free(pNodoEliminar);

				if(pNodoActual==*pCabeza && pNodoActual==*pCola)
				{
					*pCabeza = NULL;
					*pCola = NULL;
					printf("Se elimino el unico elemento %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoEliminar,xNodo.pSiguiente);
				}
				else
				{
					if(pNodoActual == *pCola)
					{
						*pCola = pNodoAnterior;
						pNodoAnterior->pSiguiente=NULL;
						printf("Se elimino del final el elemento %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoEliminar,xNodo.pSiguiente);
					}
					else
					{
						if(pNodoActual == *pCabeza)
						{
							printf("Se elimino del frente el elemento %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoEliminar,xNodo.pSiguiente);
							*pCabeza = xNodo.pSiguiente;
						}
						else
						{
							pNodoAnterior->pSiguiente = pNodoActual->pSiguiente;
							printf("Se elimino de enmedio el elemento %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoEliminar,xNodo.pSiguiente);
						}
						iResult = TRUE;
						break;
					}

				}
			}
			else
			{
				pNodoAnterior = pNodoActual;
				pNodoActual = pNodoActual->pSiguiente;
			}

		}
	}
	if(!iResult)
		printf("No se encontro un elemento con el dato indicado %d\n", xDato);
	putchar('\n');

	return (xNodo);
}

#endif /* LISTAS_ENLAZADAS2_H_ */
