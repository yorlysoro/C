/*
 * Arbol_Binario_Eliminacion.c
 * 
 * Copyright 2016 copyleft <copyleft@debian>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct NODO_ARBOL
{
	int iDato;
	struct NODO_ARBOL *pIzquierda;
	struct NODO_ARBOL *pDerecha;
}nodo_arbol;

nodo_arbol *FnArbolNodoCrea(int xDato)
{
	nodo_arbol *xNodo;
	xNodo = (nodo_arbol *)malloc(sizeof(nodo_arbol));
	
	if(xNodo == NULL)
		perror("Error. No se puede reservar memoria.");
	else
	{
		xNodo->iDato = xDato;
		xNodo->pDerecha = NULL;
		xNodo->pIzquierda = NULL;
	}
	return xNodo;
}

void SbArbolInsertarNodo(nodo_arbol **pRaiz, int xDato)
{
	nodo_arbol *pNodoNuevo;
	nodo_arbol *pAuxiliar;
	
	int iNivel = 1;
	char sLado[4] = "Der";
	
	int bResult = TRUE;
	
	int iPadre = 0;
	
	pNodoNuevo = FnArbolNodoCrea(xDato);
	
	if(*pRaiz == NULL)
	{
		*pRaiz = pNodoNuevo;
		printf("Se ha insertado el dato:%d como raiz del arbol\n", xDato);
	}
	else
	{
		pAuxiliar = *pRaiz;
		while(TRUE)
		{
			if(pAuxiliar->iDato < xDato)
				if(pAuxiliar->pDerecha != NULL)
				{
					iPadre = pAuxiliar->iDato;
					pAuxiliar = pAuxiliar->pDerecha;
				}
				else
				{
					pAuxiliar->pDerecha = pNodoNuevo;
					break;
				}
			else
				if(pAuxiliar->iDato > xDato)
					if(pAuxiliar->pIzquierda != NULL)
					{
						iPadre = pAuxiliar->iDato;
						pAuxiliar = pAuxiliar->pIzquierda;
					}
					else
					{
						pAuxiliar->pIzquierda = pNodoNuevo;
						strcpy(sLado,"Izq");
						break;
					}
				else
				{
					bResult = FALSE;
					break;
				}
			iNivel++;
		}
		if(bResult)
			printf("Se inserto el dato:%02d como hijo %s de:%02d en el nivel:%02d\n", xDato,sLado,pAuxiliar->iDato,iNivel);
		else
			printf("Error,el dato %d ya existe como hijo:%d en el nivel:%d\n",xDato,iPadre,--iNivel);
	}
}

void SbEspaciosImprime(int iNumero)
{
	int iCuenta;
	for(iCuenta = 0;iCuenta<=iNumero;iCuenta++)
		printf(" ");
}

void SbArbolRecorreNivelLado(nodo_arbol *pNodo, int iNivel, char cLado)
{
	if(pNodo == NULL)
		return;
	else
	{
		SbEspaciosImprime(iNivel*3);
		printf("%c-%d nivel %d\n",cLado,pNodo->iDato,iNivel);
		iNivel++;
		SbArbolRecorreNivelLado(pNodo->pDerecha,iNivel,'D');
		SbArbolRecorreNivelLado(pNodo->pIzquierda,iNivel,'I');
	}
}

int FnIntArbolNodos(nodo_arbol *pNodo)
{
	int iHijosDerechos = 0;
	int iHijosIzquierdos = 0;
	
	if(pNodo == NULL)
		return 0;
	else
	{
		iHijosDerechos = FnIntArbolNodos(pNodo->pDerecha);
		iHijosIzquierdos = FnIntArbolNodos(pNodo->pIzquierda);
		return 1 + iHijosDerechos + iHijosIzquierdos;
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
		printf("Nodo actual %d\n",(*pNodo)->iDato);
		if((*pNodo)->iDato == xDato)
		{
			puts("Es el dato a eliminar");
			if((*pNodo)->pDerecha == NULL && (*pNodo)->pIzquierda == NULL)
			{
				printf("Se elemina Nodo Hoja %d\n", (*pNodo)->iDato);
				*pNodo = NULL;
				free(*pNodo);
				return TRUE;
			}
			else
				if((*pNodo)->pIzquierda == NULL)
				{
					printf("Tiene solo un hijo, el derecho %d\n", (*pNodo)->pDerecha->iDato);
					(*pNodo)->iDato = (*pNodo)->pDerecha->iDato;
					printf("El hijo derecho:%d ocupo su lugar\n", (*pNodo)->iDato);
					
					pNodoEliminar = (*pNodo)->pDerecha;
					(*pNodo)->pDerecha = pNodoEliminar->pDerecha;
					(*pNodo)->pIzquierda = pNodoEliminar->pIzquierda;
					free(pNodoEliminar);
					return TRUE;
				}
				else
					if((*pNodo)->pDerecha == NULL)
					{
						printf("Tiene solo un hijo, el izquierdo %d\n", (*pNodo)->pIzquierda->iDato);
						
						(*pNodo)->iDato = (*pNodo)->pIzquierda->iDato;
						printf("El hijo izquierd:%d ocupo su lugar\n", (*pNodo)->iDato);
						pNodoEliminar = (*pNodo)->pIzquierda;
						(*pNodo)->pDerecha = pNodoEliminar->pDerecha;
						(*pNodo)->pIzquierda = pNodoEliminar->pIzquierda;
						free(pNodoEliminar);
						return TRUE;
					}
					else
					{
						puts("El dato a eliminar tiene 2 hijos");
						pNodoAuxPadre = (*pNodo);
						pNodoAuxActual = (*pNodo)->pDerecha;
						while(pNodoAuxActual->pIzquierda)
						{
							pNodoAuxPadre = pNodoAuxActual;
							pNodoAuxActual = pNodoAuxActual->pIzquierda;
						}
						(*pNodo)->iDato = pNodoAuxActual->iDato;
						
						if(pNodoAuxPadre == (*pNodo))
							pNodoAuxPadre->pDerecha = pNodoAuxActual->pDerecha;
						else
							pNodoAuxPadre->pIzquierda = pNodoAuxActual->pDerecha;
						free(pNodoAuxActual);
					}
		}
		else
			if((*pNodo)->iDato < xDato)
				FnBoolArbolBinarioEliminaNodo(&(*pNodo)->pDerecha,xDato);
			else
				FnBoolArbolBinarioEliminaNodo(&(*pNodo)->pIzquierda,xDato);
	}
}


int main(int argc, char **argv)
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

