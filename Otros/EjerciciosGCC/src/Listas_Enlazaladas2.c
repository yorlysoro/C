/*
 * Listas_Enlazaladas2.c
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#include "Listas_Enlazadas.h"
#include "Listas_Enlazadas2.h"

int main(void)
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
	printf("xNodoDireccion:%d\n", xNodo.pSiguiente);

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
