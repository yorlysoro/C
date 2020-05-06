#include "Arbol_Binario_Expresion_Evalua.h"

int main(void)
{
	nodo_arbol *pRaiz = NULL;
	printf("Creando el arbol binario\n");

    FnBoolArbolInsertarNodo(&pRaiz,'4','+', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'/','*', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'6','/', 'I');
FnBoolArbolInsertarNodo(&pRaiz,'*',' ', ' ');
    FnBoolArbolInsertarNodo(&pRaiz,'+','*', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'5','+', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'+','/', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'2','+', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'1','+', 'D');
	
	printf("El valor de la expresion del arbol es:%d\n", FnIntArbolBinarioExpresionEvalua(pRaiz));
	return 0;
}
