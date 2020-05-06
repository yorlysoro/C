#include "Arbol_Binario_Expresion.h"

int main(void)
{

    nodo_arbol *pRaiz = NULL;

    printf("Creando el arbol binario\n");

    FnBoolArbolInsertarNodo(&pRaiz,'*',' ', ' ');
    FnBoolArbolInsertarNodo(&pRaiz,'+','*', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'5','+', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'4','+', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'-','*', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'6','-', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'+','-', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'2','+', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'1','+', 'D');

    return 0;
}
