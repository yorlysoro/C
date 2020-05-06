#include "Arboles_Binarios_Busqueda.h"

int main(void)
{
	nodo_arbol *pRaiz = NULL;
	printf("Creando el arbol binario con la siguiente secuencia:10,14,2,27,25,31,5,-2,9\n");
	SbArbolInsertarNodo(&pRaiz,10);
	SbArbolInsertarNodo(&pRaiz,14);
	SbArbolInsertarNodo(&pRaiz,2);
	SbArbolInsertarNodo(&pRaiz,27);
	SbArbolInsertarNodo(&pRaiz,25);
	SbArbolInsertarNodo(&pRaiz,31);
	SbArbolInsertarNodo(&pRaiz,5);
	SbArbolInsertarNodo(&pRaiz,-2);
	SbArbolInsertarNodo(&pRaiz,9);
	
/*	printf("Realizamos Busquedas simples\n");*/
/*	*/
/*	FnBoolArbolBinarioBusquedaI(pRaiz,17) ? printf("Si se encontro el 17\n") : printf("No se encontro el 17\n");*/
/*	*/
/*	FnBoolArbolBinarioBusquedaI(pRaiz,5) ? printf("Si se encontro el 5\n") : printf("No se encontro el 5\n");*/
/*	*/
/*	FnBoolArbolBinarioBusquedaI(pRaiz,10) ? printf("Si se encontro el 10\n") : printf("No se encontro el 10\n");*/
	
	printf("Realizamos Busquedas con Nivel, Padre y Lado\n");
	
	FnBoolArbolBinarioBusquedaII(pRaiz,10,-1,0,'R') ? printf("Se encontro el 10\n") : printf("No se encontro el 10\n");
	
	FnBoolArbolBinarioBusquedaII(pRaiz,27,-1,0,'R') ? printf("Se encontro el 27\n") : printf("No se encontro el 27\n");
	
	FnBoolArbolBinarioBusquedaII(pRaiz,100,-1,0,'R') ? printf("Se encontro el 100\n") : printf("No se encontro el 100\n");
	return 0;
}
