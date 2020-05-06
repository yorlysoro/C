#include "Arboles_Binarios_Recorridos.h"

int main(void)
{
    nodo_arbol *pRaiz=NULL;

    printf("Creando el arbol binario\n");

    SbArbolInsertarNodo(&pRaiz,10);
    SbArbolInsertarNodo(&pRaiz,2);
    SbArbolInsertarNodo(&pRaiz,14);
    SbArbolInsertarNodo(&pRaiz,27);
    SbArbolInsertarNodo(&pRaiz,25);
    SbArbolInsertarNodo(&pRaiz,31);
    SbArbolInsertarNodo(&pRaiz,5);

    printf("Recorrido en Pre-Orden\n");
    SbArbolRecorridoPreOrden(pRaiz);

    printf("Recorrido en In-Orden\n");
    SbArbolRecorridoInOrden(pRaiz);

    printf("Recorrido en Post-Orden\n");
    SbArbolRecorridoPostOrden(pRaiz);

    return 0;
}
