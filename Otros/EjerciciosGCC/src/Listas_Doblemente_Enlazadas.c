/*
 * Listas_Doblemente_Enlazadas.c
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#include "Listas_Doblemente_Enlazadas.h"

int main(void)
{
	nodo *pCabeza = NULL;

	nodo xNodo;

	SbListaDobleInsertarFrente(&pCabeza,10);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);

	SbListaDobleInsertarFrente(&pCabeza,19);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);

	SbListaDobleInsertarFrente(&pCabeza,13);
	SbListaDobleInsertarFrente(&pCabeza,14);
	SbListaDobleInsertarFrente(&pCabeza,27);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleDespliega(pCabeza,FALSE);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminarFrente(&pCabeza);

	printf("Infomacion del nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliega(pCabeza,TRUE);

	SbListaDobleInsertarFrente(&pCabeza,99);

	SbListaDobleDespliega(pCabeza,TRUE);
	return 0;
}
