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

void SbArbolRecorre(nodo_arbol *pNodo)
{
	if(pNodo==NULL)
	return;
	else
	{
		printf("%d\n", pNodo->iDato);
		SbArbolRecorre(pNodo->pDerecho);
		SbArbolRecorre(pNodo->pIzquierdo);
	}
}

void SbEspaciosImprime(int iNumero)
{
	int iCuenta;
	for(iCuenta = 0; iCuenta<=iNumero; iCuenta++)
	printf(" ");
}

void SbArbolRecorreNivel(nodo_arbol *pNodo, int iNivel)
{
	if(pNodo == NULL)
	return;
	else
	{
		SbEspaciosImprime(iNivel*3);
		
		printf("%d Nivel %d\n", pNodo->iDato,iNivel);
		
		iNivel++;
		SbArbolRecorreNivel(pNodo->pDerecho,iNivel);
		SbArbolRecorreNivel(pNodo->pIzquierdo,iNivel);
	}
}

void SbArbolRecorreNivelLado(nodo_arbol *pNodo, int iNivel, char cLado)
{
	if(pNodo==NULL)
	return;
	else
	{
		SbEspaciosImprime(iNivel*3);
		
		printf("%c-%d Nivel %d\n", cLado,pNodo->iDato,iNivel);
		iNivel++;
		SbArbolRecorreNivelLado(pNodo->pDerecho,iNivel,'D');
		SbArbolRecorreNivelLado(pNodo->pIzquierdo,iNivel, 'I');
	}
}

int FnIntArbolNodos(nodo_arbol *pNodo)
{
	int iHijosDerechos=0;
	int iHijosIzquierdos=0;
	
	if(pNodo==NULL)
	return 0;
	else
	{
		iHijosDerechos=FnIntArbolNodos(pNodo->pDerecho);
		iHijosIzquierdos=FnIntArbolNodos(pNodo->pIzquierdo);
		return 1+iHijosDerechos+iHijosIzquierdos;
	}
}
int FnIntArbolAltura(nodo_arbol *pNodo, int iNivel)
{
	int iResult1 = 0;
	int iResult2 = 0;
	
	int iResult = 0;
	
	if(pNodo == NULL && iNivel == 0)
	return -1;
	else
		if(pNodo == NULL)
		return 0;
		else
		{
			iResult1=FnIntArbolAltura(pNodo->pDerecho,iNivel+1);
			iResult2=FnIntArbolAltura(pNodo->pIzquierdo,iNivel+1);
			if(iResult1>=iResult2 && iResult1>=iNivel)
			{
				return iResult1;
			}
			else
				if(iResult2>=iResult1 && iResult2 >= iNivel)
				{
					return iResult2;
				}
				else
					return iNivel;
		}
}
