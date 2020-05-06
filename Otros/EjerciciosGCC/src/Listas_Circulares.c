/*
 * Listas_Circulares.c
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */
#include "Listas_Circulares.h"

int main(void)
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
