#ifndef ARBOL_BINARIO_EXPRESION_H_INCLUDED
#define ARBOL_BINARIO_EXPRESION_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct NODO_ARBOL
{
	char cDato;
	struct NODO_ARBOL *pIzquierdo;
	struct NODO_ARBOL *pDerecho;
}nodo_arbol;


nodo_arbol *FnArbolCreaNodo(char xDato)
{
    nodo_arbol *xNodo;

    xNodo = (nodo_arbol *) malloc(sizeof(nodo_arbol));

    if(xNodo == NULL)
        printf("Error.No se puede asignar memoria para en nodo arbol\n");
    else
    {
        xNodo->cDato = xDato;
        xNodo->pDerecho = NULL;
        xNodo->pIzquierdo = NULL;
    }

    return xNodo;
}


int FnBoolArbolInsertarNodo(nodo_arbol **pRaiz, char xDatoInserta, char xDatoPadre, char cLado)
{
    nodo_arbol *pAuxiliar;

    if(*pRaiz == NULL)
    {
        nodo_arbol *pNodoNuevo;

        pNodoNuevo = FnArbolCreaNodo(xDatoInserta);

        *pRaiz=pNodoNuevo;

        printf("Se inserto el dato %c como raiz del arbol\n", xDatoInserta);

        return TRUE;
    }
    else
    {
        pAuxiliar = *pRaiz;

        if(pAuxiliar->cDato == xDatoPadre)
            if(cLado=='D')
            {
                if(pAuxiliar->pDerecho==NULL)
                {
                    nodo_arbol *pNodoNuevo;
                    pNodoNuevo = FnArbolCreaNodo(xDatoInserta);
                    pAuxiliar->pDerecho=pNodoNuevo;

                    printf("Inserto %c del lado dereche de %c\n", xDatoInserta,xDatoPadre);

                    return TRUE;
                }
            }
            else
            {
                if(pAuxiliar->pIzquierdo==NULL)
                {
                    nodo_arbol *pNodoNuevo;

                    pNodoNuevo = FnArbolCreaNodo(xDatoInserta);
                    pAuxiliar->pIzquierdo = pNodoNuevo;
                    printf("Se inserto %c de del lado izquierdo\n", xDatoInserta,xDatoPadre);
                    return TRUE;
                }
            }
            if(pAuxiliar->pIzquierdo!=NULL)
                if(!FnBoolArbolInsertarNodo(&(pAuxiliar->pIzquierdo),xDatoInserta,xDatoPadre,cLado))
                    if(pAuxiliar->pDerecho!=NULL)
                        if(!FnBoolArbolInsertarNodo(&(pAuxiliar->pDerecho),xDatoInserta,xDatoPadre,cLado))
                            return FALSE;
                        else
                            return TRUE;
                    else
                        return FALSE;
                else
                    return TRUE;
            else
                return FALSE;

    }
}

#endif // ARBOL_BINARIO_EXPRESION_H_INCLUDED
