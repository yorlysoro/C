/*
 * Listas_Doblemente_Enlazadas3.c
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
void SbListaDobleInsertar(nodo **pCabeza, nodo **pCola, int xDatoInsertar, int xDatoReferencia, int iInsertarDespuesDe)
{
	nodo *pAux;
	
	if(FnIntListaVacia(*pCabeza))
		puts("La lista esta vacia, no se pueden localizar elementos");
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
				pAux = pAux->pSiguiente;
		}
		if(pAux)
		{
			nodo *pNodoNuevo;
			pNodoNuevo = FnNodoCrea(xDatoInsertar);
			if(iInsertarDespuesDe)
			{
				if(pAux == *pCola)
					SbListaDobleInsertarFinal(&(*pCabeza),&(*pCola), xDatoInsertar);
				else
				{
					pNodoNuevo->pSiguiente = pAux->pSiguiente;
					pNodoNuevo->pAnterior = pAux;
					pAux->pSiguiente->pAnterior = pNodoNuevo;
					pAux->pSiguiente = pNodoNuevo;
					printf("Insercion Despues de Elemento:%d en direccion %p\n", xDatoInsertar, pNodoNuevo);
				}
			}
			else
			{
				if(pAux == *pCabeza)
					SbListaDobleInsertarFrente(&(*pCabeza),xDatoInsertar);
				else
				{
					pNodoNuevo->pAnterior = pAux->pAnterior;
					pNodoNuevo->pSiguiente = pAux;
					pAux->pAnterior->pSiguiente = pNodoNuevo;
					pAux->pAnterior = pNodoNuevo;
					printf("Insercion antes de elemento %d en direccion %p\n", xDatoInsertar, pNodoNuevo);
				}
			}
		}
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
nodo FnNodoListaDobleElimina(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo *pAux;
	nodo xNodo;
	
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	xNodo.pAnterior = NULL;
	
	if(FnIntListaVacia(*pCabeza))
	{
		puts("Lista Doblemente Enlazada Vacia, no es posible eliminar elemetos");
	}
	else
	{
		pAux = *pCabeza;
		while(pAux != NULL)
		{
			if(pAux->iDato == xDato)
				break;
			else
				pAux = pAux->pSiguiente;
		}
		if(pAux != NULL)
		{
			xNodo.iDato = pAux->iDato;
			xNodo.pSiguiente = pAux->pSiguiente;
			xNodo.pAnterior = pAux->pAnterior;
			
			if(pAux == *pCabeza && pAux==*pCola)
			{
				free(pAux);
				
				*pCabeza = NULL;
				*pCola = NULL;
				printf("Eliminacion del unico elemento Lista Doblemente Enlazada:%d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
			}
			else
			{
				if(pAux == *pCabeza)
					xNodo = FnNodoListaDobleEliminarFrente(&(*pCabeza));
				else
				{
					if(pAux == *pCola)
						xNodo = FnNodoListaDobleEliminaFinal(&(*pCabeza),&(*pCola));
					else
					{
						free(pAux);
						pAux->pAnterior->pSiguiente = pAux->pSiguiente;
						pAux->pSiguiente->pAnterior = pAux->pAnterior;
						printf("Eliminacion de en medio elemento Lista doblemente enlazada:%d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
					}
				}
			}
		}
		else
		{
			puts("El elemento no fue encontrado en la lista\n");
		}
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
	nodo *pCabeza =NULL;
	nodo *pCola = NULL;
	
	nodo xNodo;
	
	SbListaDobleInsertarFinal(&pCabeza,&pCola,10);
	SbListaDobleInsertarFinal(&pCabeza,&pCola,20);
	SbListaDobleInsertarFinal(&pCabeza,&pCola,30);
	
	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);
	
	SbListaDobleInsertar(&pCabeza,&pCola,15,20,FALSE);
	SbListaDobleInsertar(&pCabeza,&pCola,25,20,FALSE);
	
	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);
	
	SbListaDobleInsertar(&pCabeza,&pCola,5,10,FALSE);
	SbListaDobleInsertar(&pCabeza,&pCola,35,30,TRUE);
	
	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);
	
	xNodo = FnNodoListaDobleElimina(&pCabeza,&pCola,75);
	
	xNodo = FnNodoListaDobleElimina(&pCabeza,&pCola,15);
	
	printf("Infomacion del nodo:%d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
	
	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);
	
	xNodo = FnNodoListaDobleElimina(&pCabeza,&pCola,5);
	
	printf("Infomacion del nodo:%d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
	xNodo = FnNodoListaDobleElimina(&pCabeza,&pCola,35);
	printf("Infomacion del nodo:%d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);
	
	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);
	return 0;
}

