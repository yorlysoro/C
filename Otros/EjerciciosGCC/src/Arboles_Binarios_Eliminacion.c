#include "Arboles_Binarios_Eliminacion.h"

int main(void)
{
	nodo_arbol *pRaiz = NULL;
	
	printf("Creando el arbol binario\n");
	SbArbolInsertarNodo(&pRaiz,10);
	
	FnBoolArbolBinarioEliminaNodo(&pRaiz,10);
	
	printf("1.-Desplegando el Arbol\n");
	SbArbolRecorreNivelLado(pRaiz,0,'R');
	
	printf("El arbol tiene %d nodos\n", FnIntArbolNodos(pRaiz));
	
	SbArbolInsertarNodo(&pRaiz,10);
	SbArbolInsertarNodo(&pRaiz,14);
	printf("2.-Desplegando el Arbol\n");
	SbArbolRecorreNivelLado(pRaiz,0,'R');
	
	printf("El arbol tiene %d nodos\n", FnIntArbolNodos(pRaiz));
	
	FnBoolArbolBinarioEliminaNodo(&pRaiz,10);
	
	printf("3.-Desplegando el Arbol\n");
	SbArbolRecorreNivelLado(pRaiz,0,'R');
	
	printf("El arbol tiene %d nodos\n", FnIntArbolNodos(pRaiz));
	FnBoolArbolBinarioEliminaNodo(&pRaiz,14);
	SbArbolInsertarNodo(&pRaiz,10);
	SbArbolInsertarNodo(&pRaiz,2);
	SbArbolInsertarNodo(&pRaiz,14);
	SbArbolInsertarNodo(&pRaiz,27);
	SbArbolInsertarNodo(&pRaiz,25);
	SbArbolInsertarNodo(&pRaiz,31);
	SbArbolInsertarNodo(&pRaiz,5);
	SbArbolInsertarNodo(&pRaiz,-2);
	SbArbolInsertarNodo(&pRaiz,19);
	SbArbolInsertarNodo(&pRaiz,-9);
	SbArbolInsertarNodo(&pRaiz,39);
	SbArbolInsertarNodo(&pRaiz,49);
	SbArbolInsertarNodo(&pRaiz,59);
	
	printf("Desplegando el Arbol y sus nodos\n");
	SbArbolRecorreNivelLado(pRaiz,0,'R');
	
	printf("El arbol tiene %d nodos\n", FnIntArbolNodos(pRaiz));
	
	FnBoolArbolBinarioEliminaNodo(&pRaiz,59);
	FnBoolArbolBinarioEliminaNodo(&pRaiz,49);
	
	printf("Desplegando el Arbol y sus nodos\n");
	SbArbolRecorreNivelLado(pRaiz,0,'R');
	
	printf("El arbol tiene %d nodos\n", FnIntArbolNodos(pRaiz));
	return 0;
}
