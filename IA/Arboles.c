/*
 * Arboles.c
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

typedef struct NODO_ARBOL{
	int iDato;
	struct NODO_ARBOL *pIzquierda;
	struct NODO_ARBOL *pDerecha;
}nodo_arbol;

nodo_arbol *FnArbolNodoCrea(int xDato)
{
	nodo_arbol *xNodo;
	xNodo = (nodo_arbol *)malloc(sizeof(nodo_arbol));
	
	if(xNodo == NULL)
		perror("Error.No se puede asignar memoria.");
	else
	{
		xNodo->iDato = xDato;
		xNodo->pDerecha = NULL;
		xNodo->pIzquierda = NULL;
	}
	return xNodo;
}

void SbArbolInsertarNodo(nodo_arbol **pRaiz,int xDato)
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
						iPadre=pAuxiliar->iDato;
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
			printf("Se inserto el Dato:%02d como hijo %s de:%02d en el nnivel:%d\n", xDato,sLado,pAuxiliar->iDato, iNivel);
		else
			printf("Error, el dato %d ya existe como hijo:%d en el nivel:%d\n",xDato,iPadre,--iNivel);
	}
}

int main(int argc, char **argv)
{
	nodo_arbol *pRaiz=NULL;
	
	SbArbolInsertarNodo(&pRaiz,10);
	SbArbolInsertarNodo(&pRaiz,14);
	SbArbolInsertarNodo(&pRaiz,10);
	SbArbolInsertarNodo(&pRaiz,2);
	SbArbolInsertarNodo(&pRaiz,27);
	SbArbolInsertarNodo(&pRaiz,25);
	SbArbolInsertarNodo(&pRaiz,31);
	SbArbolInsertarNodo(&pRaiz,5);
	SbArbolInsertarNodo(&pRaiz,-2);
	SbArbolInsertarNodo(&pRaiz,9);
	SbArbolInsertarNodo(&pRaiz,9);
	SbArbolInsertarNodo(&pRaiz,9);
	return 0;
}

