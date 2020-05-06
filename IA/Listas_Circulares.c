/*
 * Listas_Circulares.c
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
void SbListaCircularInsertar(nodo **pCola, int xDato)
{
	nodo *pNodoNuevo;
	
	pNodoNuevo = FnNodoCrea(xDato);
	
	if(FnIntListaVacia(*pCola))
	{
		pNodoNuevo->pSiguiente = pNodoNuevo;
		*pCola = pNodoNuevo;
		printf("Insercion al final con lista circular vacia, el elemento %d en direccion %p\n", xDato, pNodoNuevo);
	}
	else
	{
		pNodoNuevo->pSiguiente = (*pCola)->pSiguiente;
		
		(*pCola)->pSiguiente = pNodoNuevo;
		
		*pCola=pNodoNuevo;
		printf("Insercion al fina con lista circular vacia, el elemento %d en direccion %p\n", xDato, pNodoNuevo);
	}
}

nodo FnNodoListaCircularElimina(nodo **pCola)
{
	nodo *pAux;
	nodo xNodo;
	
	xNodo.iDato = -1;
	xNodo.pSiguiente = NULL;
	
	if(FnIntListaVacia(*pCola))
	{
		puts("La lista circular esta vacia");
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
			
			printf("Eliminacion del frente de la cola circular: %d que apuntaba a:%p\n", xNodo.iDato, xNodo.pSiguiente);
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
		puts("La lista circular se encuentra vacia");
	}
	else
	{
		pAuxiliar = pCola->pSiguiente;
		
		puts("Desplegando los elementos de la lista...\n");
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
		puts("La lista circular esta vacia, no hay valores que desplegar\n");
	}
	else
	{
		pAuxiliar = (*pCola)->pSiguiente;
		puts("Eliminando los elementos de lista circular");
		while(*pCola!=pAuxiliar)
		{
			free(pAuxiliar);
			pAuxiliar = pAuxiliar->pSiguiente;
		}
		free(*pCola);
		*pCola = NULL;
	}
	puts("Todos los elementos de la lista circular fueron eliminados");
}
int main(int argc, char **argv)
{
	nodo *pCola=NULL;

	nodo xNodo;

	SbListaCircularInsertar(&pCola,30);

	SbListaCircularDespliega(pCola);

	xNodo = FnNodoListaCircularElimina(&pCola);
	printf("xNodo.iDato :%d\n", xNodo.iDato);
	printf("xNodo.pSiguiente: %p\n", xNodo.pSiguiente);

	SbListaCircularDespliega(pCola);

	SbListaCircularInsertar(&pCola, 22);
	SbListaCircularInsertar(&pCola, 40);

	SbListaCircularDespliega(pCola);

	xNodo = FnNodoListaCircularElimina(&pCola);
	printf("xNodo.iDato :%d\n", xNodo.iDato);
	printf("xNodo.pSiguiente: %p\n", xNodo.pSiguiente);

	SbListaCircularInsertar(&pCola,45);
	SbListaCircularDespliega(pCola);

	xNodo = FnNodoListaCircularElimina(&pCola);
	printf("xNodo.iDato :%d\n", xNodo.iDato);
	printf("xNodo.pSiguiente: %p\n", xNodo.pSiguiente);

	SbListaCircularDespliega(pCola);

	xNodo = FnNodoListaCircularElimina(&pCola);
	printf("xNodo.iDato :%d\n", xNodo.iDato);
	printf("xNodo.pSiguiente: %p\n", xNodo.pSiguiente);

	SbListaCircularDespliega(pCola);

	xNodo = FnNodoListaCircularElimina(&pCola);
	printf("xNodo.iDato :%d\n", xNodo.iDato);
	printf("xNodo.pSiguiente: %p\n", xNodo.pSiguiente);

	SbListaCircularDespliega(pCola);

	SbListaCircularInsertar(&pCola, 40);
	SbListaCircularInsertar(&pCola, 50);
	SbListaCircularInsertar(&pCola, 60);
	SbListaCircularDespliega(pCola);

	SbListaCircularInicializa(&pCola);

	SbListaCircularDespliega(pCola);
	return 0;
}

