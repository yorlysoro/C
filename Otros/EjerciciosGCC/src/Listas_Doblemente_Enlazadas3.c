#include "Listas_Doblemente_Enlazadas3.h"
#include "Listas_Doblemente_Enlazadas2.h"
#include "Listas_Doblemente_Enlazadas.h"
int main(void)
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
