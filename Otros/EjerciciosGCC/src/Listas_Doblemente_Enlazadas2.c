/*
 * Listas_Doblemente_Enlazadas2.c
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */
#include "Listas_Doblemente_Enlazadas2.h"

int main(void)
{
	nodo *pCabeza = NULL;
	nodo *pCola = NULL;

	nodo xNodo;

	SbListaDobleInsertarFinal(&pCabeza,&pCola,10);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,20);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,30);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,40);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,50);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleDespliegaFull(pCabeza,pCola,FALSE);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleDespliegaFull(pCabeza,pCola,FALSE);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);


	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	xNodo = FnNodoListaDobleEliminaFinal(&pCabeza,&pCola);

	printf("Informacion del Nodo: %d Sigte:%p Anter:%p\n", xNodo.iDato, xNodo.pSiguiente, xNodo.pAnterior);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,99);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,98);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,97);

	SbListaDobleInsertarFinal(&pCabeza,&pCola,96);

	SbListaDobleDespliegaFull(pCabeza,pCola,TRUE);

	printf("Accediendo todos los Nodos desde Cabeza\n");

	printf("%d\n", pCabeza->iDato);
	printf("%d\n", pCabeza->pSiguiente->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->pAnterior->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->pAnterior->pAnterior->iDato);
	printf("%d\n", pCabeza->pSiguiente->pSiguiente->pSiguiente->pAnterior->pAnterior->pAnterior->iDato);

	return 0;
}

