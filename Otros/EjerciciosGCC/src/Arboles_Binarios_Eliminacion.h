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
void SbEspaciosImprime(int iNumero)
{
	int iCuenta;
	for(iCuenta = 0; iCuenta<=iNumero; iCuenta++)
	printf(" ");
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

int FnBoolArbolBinarioEliminaNodo(nodo_arbol **pNodo, int xDato)
{
	nodo_arbol *pNodoAuxActual;
	nodo_arbol *pNodoAuxPadre;
	nodo_arbol *pNodoEliminar;
	
	if(*pNodo == NULL)
	return FALSE;
	else
	{
		printf("Nodo actual %d\n", (*pNodo)->iDato);
		if((*pNodo)->iDato == xDato)
		{
			printf("Es el dato a Eliminar\n");
			
			if((*pNodo)->pDerecho == NULL && (*pNodo)->pIzquierdo==NULL)
			{
				printf("Se elimino Nodo Hoja %d\n", (*pNodo)->iDato);
				*pNodo=NULL;
				free(*pNodo);
				return TRUE;
			}
			else
			if((*pNodo)->pIzquierdo==NULL)
			{
				printf("Tiene solo un hijo, el derecho:%d\n", (*pNodo)->pDerecho->iDato);
				
				(*pNodo)->iDato=(*pNodo)->pDerecho->iDato;
				printf("El hijo derecho:%d ocupo su lugar \n", (*pNodo)->iDato);
				
				pNodoEliminar = (*pNodo)->pDerecho;
				(*pNodo)->pDerecho = pNodoEliminar->pDerecho;
				(*pNodo)->pIzquierdo = pNodoEliminar->pIzquierdo;
				free(pNodoEliminar);
				return TRUE;
			}
			else
			if((*pNodo)->pDerecho == NULL)
			{
				printf("Tiene solo un hijo, el izquierdo:%d\n", (*pNodo)->pIzquierdo->iDato);
				
				(*pNodo)->iDato=(*pNodo)->pIzquierdo->iDato;
				printf("El hijo izquierdo:%d ocupo su lugar \n", (*pNodo)->iDato);
				
				pNodoEliminar = (*pNodo)->pIzquierdo;
				(*pNodo)->pDerecho= pNodoEliminar->pDerecho;
				(*pNodo)->pIzquierdo = pNodoEliminar->pIzquierdo;
				free(pNodoEliminar);
				return TRUE;
			}
			else
			{
				printf("El dato a eliminar tiene 2 hijos \n");
				pNodoAuxPadre=(*pNodo);
				pNodoAuxActual=(*pNodo)->pDerecho;
				while(pNodoAuxActual->pIzquierdo)
				{
					pNodoAuxPadre=pNodoAuxActual;
					pNodoAuxActual = pNodoAuxActual->pIzquierdo;	
					
				}
				(*pNodo)->iDato = pNodoAuxActual->iDato;
				
				if(pNodoAuxPadre == (*pNodo))
				pNodoAuxPadre->pDerecho=pNodoAuxActual->pDerecho;
				else
				pNodoAuxPadre->pIzquierdo = pNodoAuxActual->pDerecho;
				free(pNodoAuxActual);
			}
		}
		else
			if((*pNodo)->iDato < xDato)
				FnBoolArbolBinarioEliminaNodo(&(*pNodo)->pDerecho,xDato);
			else
				FnBoolArbolBinarioEliminaNodo(&(*pNodo)->pIzquierdo,xDato);
				
				
	}
}
