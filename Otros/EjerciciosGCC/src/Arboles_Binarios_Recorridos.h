#ifndef ARBOLES_BINARIOS_RECORRIDOS_H_INCLUDED
#define ARBOLES_BINARIOS_RECORRIDOS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct NODO_ARBOL
{
	int iDato;
	struct NODO_ARBOL *pIzquierdo;
	struct NODO_ARBOL *pDerecho;
}nodo_arbol;

nodo_arbol *FnArbolNodoCrea(int xDato)
{
	nodo_arbol *xNodo;
	xNodo = (nodo_arbol *)malloc(sizeof(nodo_arbol));

	if(xNodo == NULL)
	printf("Error.No se puede reservar memoria\n");
	else
	{
		xNodo->iDato = xDato;
		xNodo->pDerecho = NULL;
		xNodo->pIzquierdo = NULL;
	}
	return xNodo;
}

void SbArbolInsertarNodo(nodo_arbol **pRaiz, int xDato)
{
	nodo_arbol *pNodoNuevo;
	nodo_arbol *pAuxiliar;

	int iNivel=1;

	char sLado[4] = "Der";

	int bResult = TRUE;

	int iPadre= 0;
	pNodoNuevo = FnArbolNodoCrea(xDato);

	if(*pRaiz==NULL)
	{
		*pRaiz=pNodoNuevo;
		printf("Se ha insertado el dato:%d como raiz del arbol\n", xDato);
	}
	else
	{
		pAuxiliar = *pRaiz;
		while(TRUE)
		{
			if(pAuxiliar->iDato < xDato)
				if(pAuxiliar->pDerecho!=NULL)
				{
					iPadre=pAuxiliar->iDato;
					pAuxiliar=pAuxiliar->pDerecho;
				}
				else
				{
					pAuxiliar->pDerecho=pNodoNuevo;
					break;
				}
			else
				if(pAuxiliar->iDato > xDato)
					if(pAuxiliar->pIzquierdo !=NULL)
					{
						iPadre=pAuxiliar->iDato;
						pAuxiliar=pAuxiliar->pIzquierdo;
					}
					else
					{
						pAuxiliar->pIzquierdo=pNodoNuevo;
						strcpy(sLado,"Izq");
						break;
					}
				else
				{
					bResult=FALSE;
					break;
				}
			iNivel++;

		}
		if(bResult)
		printf("Se inserto el Dato:%02d como hijo %s de:%02d en el nivel:%d\n", xDato,sLado,pAuxiliar->iDato,iNivel);
		else
		printf("Error, el dato %d ya existe como hijo :%d en el nivel:%d\n", xDato,iPadre,--iNivel);
	}
}

void SbArbolRecorridoPreOrden(nodo_arbol *pNodo)
{
    if(pNodo == NULL)
    return;
    else
    {
        printf("%d\n", pNodo->iDato);
        SbArbolRecorridoPreOrden(pNodo->pIzquierdo);
        SbArbolRecorridoPreOrden(pNodo->pDerecho);
    }
}

void SbArbolRecorridoInOrden(nodo_arbol *pNodo)
{
    if(pNodo == NULL)
    return;
    else
    {
        SbArbolRecorridoInOrden(pNodo->pIzquierdo);
        printf("%d\n",pNodo->iDato);
        SbArbolRecorridoInOrden(pNodo->pDerecho);
    }
}

void SbArbolRecorridoPostOrden(nodo_arbol *pNodo)
{
    if(pNodo==NULL)
    return;
    else
    {
        SbArbolRecorridoPostOrden(pNodo->pIzquierdo);
        SbArbolRecorridoPostOrden(pNodo->pDerecho);
        printf("%d\n", pNodo->iDato);
    }
}

#endif // ARBOLES_BINARIOS_RECORRIDOS_H_INCLUDED
