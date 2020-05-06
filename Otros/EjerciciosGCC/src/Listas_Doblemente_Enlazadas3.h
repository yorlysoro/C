#include "Listas_Doblemente_Enlazadas.h"
#include "Listas_Doblemente_Enlazadas2.h"

nodo FnNodoListaDobleEliminarFrente(nodo **pCabeza);

nodo FnNodoListaDobleEliminaFinal(nodo **pCabeza, nodo **pCola);

void SbListaDobleInsertar(nodo **pCabeza, nodo **pCola, int xDatoInsertar, int xDatoReferencia, int iInsertarDespuesDe)
{
	nodo *pAux;

	if(FnIntListaVacia(*pCabeza))
	{
		printf("La lista esta vacia, no se pueden localizar elementos\n");
	}
	else
	{
		pAux = *pCabeza;
		while(pAux != NULL)
		{
			if(pAux->iDato == xDatoReferencia)
			{
				break;
			}
			else
				pAux=pAux->pSiguiente;
		}
		if(pAux)
		{
			nodo *pNodoNuevo;
			pNodoNuevo=FnNodoCrea(xDatoInsertar);
			if(iInsertarDespuesDe)
			{
				if(pAux==*pCola)
					SbListaDobleInsertarFinal(&(*pCabeza),&(*pCola),xDatoInsertar);
				else
				{
					pNodoNuevo->pSiguiente = pAux->pSiguiente;
					pNodoNuevo->pAnterior = pAux;
					pAux->pSiguiente->pAnterior=pNodoNuevo;
					pAux->pSiguiente=pNodoNuevo;
					printf("Insercion Despues de Elemento:%d en direccion %p\n\n", xDatoInsertar,pNodoNuevo);
				}
			}
			else
			{
				if(pAux==*pCabeza)
					SbListaDobleInsertarFrente(&(*pCabeza),xDatoInsertar);
				else
				{
					pNodoNuevo->pAnterior=pAux->pAnterior;
					pNodoNuevo->pSiguiente = pAux;
					pAux->pAnterior->pSiguiente = pNodoNuevo;
					pAux->pAnterior = pNodoNuevo;
					printf("Insercion antes de Elemente %d en direccion %p\n\n", xDatoInsertar, pNodoNuevo);
				}
			}
		}
	}
}

nodo FnNodoListaDobleElimina(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo *pAux;
	nodo xNodo;
	
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	xNodo.pAnterior = NULL;
	
	if(FnIntListaVacia(*pCabeza))
	{
		printf("La lista doblemente enlazada esta vacia, no es posible eliminar elementos \n\n");
	}
	else
	{
		pAux = *pCabeza;
		while(pAux!=NULL)
		{
			if(pAux->iDato==xDato)
			break;
			else
			pAux=pAux->pSiguiente;
		}
		if(pAux!=NULL)
		{
			xNodo.iDato = pAux->iDato;
			xNodo.pSiguiente = pAux->pSiguiente;
			xNodo.pAnterior = pAux->pAnterior;
			
			if(pAux==*pCabeza && pAux==*pCola)
			{
				free(pAux);
				
				*pCabeza=NULL;
				*pCola = NULL;
				printf("Eliminacion del unico elemento Lista doblemente enlazada:%d Sigte:%p Anter:%p\n\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
			}
			else
				if(pAux==*pCabeza)
				xNodo=FnNodoListaDobleEliminarFrente(&(*pCabeza));
				else
					if(pAux==*pCola)
					xNodo=FnNodoListaDobleEliminaFinal(&(*pCabeza),&(*pCola));
					else
					{
						free(pAux);
						pAux->pAnterior->pSiguiente=pAux->pSiguiente;
						pAux->pSiguiente->pAnterior=pAux->pAnterior;
						printf("Eliminacion de en medio elemento Lista doblemente enlazada:%d Sigte:%p Anter:%p\n\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);		
					}
		}
		else
			printf("Elemento no fue encontrado en la lista\n\n");
		
	}
	return (xNodo);
}
