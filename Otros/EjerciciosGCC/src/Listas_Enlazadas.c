/*
 * Listas_Enlazadas.c
 *
 *  Created on: 09/11/2016
 *      Author: yorlys
 */

#include "Listas_Enlazadas.h"

int main(void)
{
	nodo xNodo;
	nodo *pCabeza = NULL;
	printf("El tamaño en bytes de pCabeza:%d \n\n", sizeof(pCabeza));

	SbListaInsertar(&pCabeza,20);
	SbListaDespliega(pCabeza);

	xNodo = FnNodoListaElimina(&pCabeza);

	SbListaDespliega(pCabeza);

	SbListaInsertar(&pCabeza,25);
	SbListaDespliega(pCabeza);

	SbListaInsertar(&pCabeza,27);
	SbListaInsertar(&pCabeza,72);

	SbListaDespliega(pCabeza);

	FnIntListaBuscaNodo(pCabeza,72);


	return 0;
}
