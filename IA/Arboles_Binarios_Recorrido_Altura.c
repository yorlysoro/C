/*
 * Arboles_Binarios_Recorrido_Altura.c
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
	xNodo =(nodo_arbol *)malloc(sizeof(nodo_arbol));
	
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
	pNodoNuevo = FnArbolNodoCrea(xDato);
	
	int iNivel = 1;
	char sLado[4] = "Der";
	int bResult = TRUE;
	
	int iPadre = 0;
	if(*pRaiz == NULL)
	{
		*pRaiz = pNodoNuevo;
		printf("Se ha insertado el dato %d como raiz del arbol\n", xDato);
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
						strcpy(sLado, "Izq");
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
			printf("Se inserto el dato: %02d como hijo %s de:%02d en el nivel:%d\n", xDato,sLado,pAuxiliar->iDato,iNivel);
		else
			printf("Error, el dato %d ya existe como hijo:%d en el nivel:%d\n", xDato, iPadre,--iNivel);
	}
}
void SbArbolRecorre(nodo_arbol *pNodo)
{
	if(pNodo==NULL)
		return;
	else
	{
		printf("%d\n",pNodo->iDato);
		SbArbolRecorre(pNodo->pDerecha);
		SbArbolRecorre(pNodo->pIzquierda);
	}
}

void SbEspaciosImprime(int iNumero)
{
	int iCuenta;
	for(iCuenta = 0; iCuenta<=iNumero;iCuenta++)
		printf(" ");
}

void SbArbolRecorreNivel(nodo_arbol *pNodo, int iNivel)
{
	if(pNodo == NULL)
		return;
	else
	{
		SbEspaciosImprime(iNivel*3);
		printf("%d Nivel %d\n", pNodo->iDato, iNivel);
		
		iNivel++;
		SbArbolRecorreNivel(pNodo->pDerecha,iNivel);
		SbArbolRecorreNivel(pNodo->pIzquierda,iNivel);
	}
}

void SbArbolRecorreNivelLado(nodo_arbol *pNodo, int iNivel, char cLado)
{
	if(pNodo == NULL)
		return;
	else
	{
		SbEspaciosImprime(iNivel*3);
		iNivel++;
		SbArbolRecorreNivelLado(pNodo->pDerecha,iNivel,'D');
		SbArbolRecorreNivelLado(pNodo->pIzquierda,iNivel,'I');
	}
}

int FnIntArbolNodos(nodo_arbol *pNodo)
{
	int iHijoDerechos = 0;
	int iHijoIzquierdos = 0;
	
	if(pNodo == NULL)
		return 0;
	else
	{
		iHijoDerechos = FnIntArbolNodos(pNodo->pDerecha);
		iHijoIzquierdos = FnIntArbolNodos(pNodo->pIzquierda);
		return 1 + iHijoDerechos + iHijoIzquierdos;
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
			iResult1 = FnIntArbolAltura(pNodo->pDerecha,iNivel+1);
			iResult2 = FnIntArbolAltura(pNodo->pIzquierda, iNivel+1);
			if(iResult1 >= iResult2 && iResult1 >=  iNivel)
				return iResult1;
			else
				if(iResult2 >= iResult1 && iResult2 >= iNivel)
					return iResult2;
				else
					return iNivel;
		}
}

int main(int argc, char **argv)
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
	
	printf("Recorrido Simple del Arbol\n");
	SbArbolRecorre(pRaiz);
	
	printf("Recorrido del arbol con nivel, indentacion\n");
	SbArbolRecorreNivel(pRaiz,0);
	
	SbArbolRecorreNivelLado(pRaiz,0,'R');
	
	printf("Nodos del Arbo:%d\n", FnIntArbolNodos(pRaiz));
	
	printf("Altura del arbol:%d\n", FnIntArbolAltura(pRaiz,0));
	return 0;
}

