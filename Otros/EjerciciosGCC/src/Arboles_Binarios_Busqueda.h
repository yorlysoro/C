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
						pAuxiliar=pAuxiliar->pIzs quierdo;
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

int FnBoolArbolBinarioBusquedaI(nodo_arbol *pNodo, int xDato)
{
	if(pNodo == NULL)
	return FALSE;
	else
		if(pNodo->iDato == xDato)
		return TRUE;
		else
			if(FnBoolArbolBinarioBusquedaI(pNodo->pDerecho,xDato))
			return TRUE;
			else
				if(FnBoolArbolBinarioBusquedaI(pNodo->pIzquierdo,xDato))
				return TRUE;
				else
				return FALSE;
}

int FnBoolArbolBinarioBusquedaII(nodo_arbol *pNodo, int xDato, int iNodoPadre, int iNivel, char cLado)
{
	char strLado[4];
	
	if(pNodo == NULL && iNivel == 0)
	{
		printf("El arbol esta vacio\n");
		return FALSE;
	}
	else
		if(pNodo == NULL)
		return FALSE;
		else
			if(pNodo->iDato == xDato)
			{
				printf("El dato %d fue encontrado en el nivel:%d\n",xDato,iNivel);
				if(iNivel == 0)
				printf("El dato %d no tiene padre, fue encontrado en la raiz del arbol\n", xDato);
				else
				{
					cLado == 'D' ? strcpy(strLado,"Der") : strcpy(strLado, "Izq");
					printf("El padre del dato es:%d y es hijo %s\n", iNodoPadre,strLado);
				}
				return TRUE;
			}
			else
			{
				iNivel++;
				
				if(FnBoolArbolBinarioBusquedaII(pNodo->pDerecho,xDato,pNodo->iDato,iNivel,'D'))
				return TRUE;
				else
				if(FnBoolArbolBinarioBusquedaII(pNodo->pIzquierdo,xDato,pNodo->iDato,iNivel, 'I'))
				return TRUE;
				else
				return FALSE;
			}
}
