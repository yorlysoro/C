#include "Arboles_Binarios_Recorrido_Altura.h"


int main(void)
{
	nodo_arbol *pRaiz=NULL;

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
	
	SbArbolInsertarNodo(&pRaiz,19);
	SbArbolInsertarNodo(&pRaiz,-9);
	SbArbolInsertarNodo(&pRaiz,39);
	SbArbolInsertarNodo(&pRaiz,49);
	SbArbolInsertarNodo(&pRaiz,59);
	
	//printf("Recorrido Simple del Arbol\n");
	//SbArbolRecorre(pRaiz);
	
	//printf("Recorrido del arbol con nivel, indentacion\n");
	//SbArbolRecorreNivel(pRaiz,0);
	
	//SbArbolRecorreNivelLado(pRaiz,0,'R');
	
	//printf("Nodos del Arbo:%d\n", FnIntArbolNodos(pRaiz));
	
	printf("Altura del arbol:%d\n", FnIntArbolAltura(pRaiz,0));
	
	return 0;
	
}
