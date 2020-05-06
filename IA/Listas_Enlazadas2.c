/*
 * Listas_Enlazadas2.c
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

void SbListaInsertarFinal(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo *pNodoNuevo;
	nodo *pAux;
	
	pNodoNuevo = FnNodoCrea(xDato);
	
	if(FnIntListaVacia(*pCabeza))
	{
		*pCabeza = pNodoNuevo;
		*pCola = pNodoNuevo;
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
	char iContar = 0;
	char iResult = FALSE;
	
	puts("Buscando el elemento para insertar despues de el ...");
	
	while(pCabeza!=NULL)
	{
		iContar++;
		if(pCabeza->iDato == xDatoDespuesDe)
		{
			iResult = TRUE;
			pNodoNuevo = FnNodoCrea(xDatoInsertar);
			if(pCabeza == *pCola)
			{
				(*pCola)->pSiguiente = pNodoNuevo;
				*pCola = pNodoNuevo;
				
				printf("Se ha insertado el elemento %d en el final de la lista despues de %d\n", xDatoInsertar,xDatoDespuesDe);
			}
			else
			{
				pNodoNuevo->pSiguiente = pCabeza->pSiguiente;
				pCabeza->pSiguiente = pNodoNuevo;
				printf("Se ha insertado el elemento: %d en la lista, despues de %d\n", xDatoInsertar, xDatoDespuesDe);
			}
			break;
		}
		else
			pCabeza = pCabeza->pSiguiente;
	}
	if(!iResult)
		printf("El elemento a buscar %d para insertar despues, no fue encontrado\n", xDatoDespuesDe);
	putchar('\n');
}

nodo FnNodoListaEliminaFinal(nodo **pCabeza, nodo **pCola)
{
	nodo xNodo;
	nodo *pNodoAuxiliar;
	
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	
	if(FnIntListaVacia(*pCabeza))
		puts("La lista esta vacia");
	else
	{
		if(*pCabeza == *pCola)
		{
			pNodoAuxiliar = *pCabeza;
			xNodo.iDato = pNodoAuxiliar->iDato;
			xNodo.pSiguiente = pNodoAuxiliar->pSiguiente;
			
			free(pNodoAuxiliar);
			
			*pCola = NULL;
			*pCabeza = NULL;
			
			printf("Se ha eliminado del final el unico elemento que habia: %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoAuxiliar,xNodo.pSiguiente);
		}
		else
		{
			pNodoAuxiliar = *pCabeza;
			while(pNodoAuxiliar->pSiguiente!=*pCola)
			{
				pNodoAuxiliar = pNodoAuxiliar->pSiguiente;
			}
			
			xNodo.iDato = (*pCola)->iDato;
			xNodo.pSiguiente = (*pCola)->pSiguiente;
			free(*pCola);
			
			*pCola = pNodoAuxiliar;
			
			pNodoAuxiliar->pSiguiente = NULL;
			
			printf("Se ha eliminado del fina el elemento:%d en direccion:%p que apuntaba a:%p\n", xNodo.iDato, pNodoAuxiliar, xNodo.pSiguiente);
		}
	}
	return(xNodo);
}

nodo FnNodoListaEliminaDato(nodo **pCabeza, nodo **pCola, int xDato)
{
	nodo xNodo;
	nodo *pNodoAnterior = NULL;
	nodo *pNodoActual = NULL;
	nodo *pNodoEliminar = NULL;
	
	int iResult = FALSE;
	
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	
	if(FnIntListaVacia(*pCabeza))
		puts("La lista esta vacia no se pueden eliminar elementos");
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
					printf("Se elimino el unico elemento %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoEliminar, xNodo.pSiguiente);
				}
				else
				{
					if(pNodoActual == *pCola)
					{
						*pCola = pNodoAnterior;
						pNodoAnterior->pSiguiente=NULL;
						printf("Se elimino del fina el elemento %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoEliminar, xNodo.pSiguiente);
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
							printf("Se elimino de en medio %d en direccion:%p que apuntaba:%p\n", xNodo.iDato, pNodoEliminar, xNodo.pSiguiente);
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
		printf("No se encontro un element con el dato indicado %d\n", xDato);
	putchar('\n');
	
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


int main(int argc, char **argv)
{
	nodo *pCabeza = NULL;
	nodo *pCola = NULL;

	nodo xNodo;

	SbListaInsertarFinal(&pCabeza,&pCola,20);

	SbListaDespliega(pCabeza);

	SbListaInsertarFinal(&pCabeza,&pCola,30);

	SbListaDespliega(pCabeza);

	SbListaInsertarFinal(&pCabeza,&pCola, 40);

	SbListaDespliega(pCabeza);

	SbListaInsertarDespues(pCabeza,&pCola,20,25);

	SbListaDespliega(pCabeza);

	SbListaInsertarDespues(pCabeza,&pCola,40,55);

	SbListaDespliega(pCabeza);
	
	xNodo = FnNodoListaEliminaFinal(&pCabeza,&pCola);
	printf("xNodoValor:%d\n", xNodo.iDato);
	printf("xNodoDireccion:%p\n", xNodo.pSiguiente);

	FnNodoListaEliminaFinal(&pCabeza,&pCola);
	FnNodoListaEliminaFinal(&pCabeza,&pCola);
	FnNodoListaEliminaFinal(&pCabeza,&pCola);
	FnNodoListaEliminaFinal(&pCabeza,&pCola);

	SbListaDespliega(pCabeza);
	
	SbListaInsertarFinal(&pCabeza,&pCola,55);

	SbListaDespliega(pCabeza);

	FnNodoListaEliminaDato(&pCabeza,&pCola,55);

	SbListaInsertarFinal(&pCabeza,&pCola,65);

	SbListaInsertarFinal(&pCabeza,&pCola,75);

	SbListaInsertarFinal(&pCabeza,&pCola,85);

	SbListaInsertarFinal(&pCabeza,&pCola,93);

	SbListaInsertarFinal(&pCabeza,&pCola,95);

	SbListaDespliega(pCabeza);

	FnNodoListaEliminaDato(&pCabeza,&pCola,95);

	SbListaDespliega(pCabeza);

	FnNodoListaEliminaDato(&pCabeza,&pCola,65);

	SbListaDespliega(pCabeza);

	FnNodoListaEliminaDato(&pCabeza,&pCola,85);

	SbListaDespliega(pCabeza);

	return 0;
}

