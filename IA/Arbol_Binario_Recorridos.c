/*
 * Arbol_Binario_Recorridos.c
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
		perror("Error al asignar memoria al nodo");
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
			printf("Se inserto el dato:%02d como hijo %s de:%02d en el nivel:%d\n",xDato,sLado,pAuxiliar->iDato,iNivel);
		else
			printf("Error, el dato %d ya existe como hijo:%d en el nivel:%d\n", xDato,iPadre,--iNivel);
	}
}

void SbArbolRecorrePreOrden(nodo_arbol *pNodo)
{
	if(pNodo == NULL)
		return;
	else
	{
		printf("%d\n", pNodo->iDato);
		SbArbolRecorrePreOrden(pNodo->pIzquierda);
		SbArbolRecorrePreOrden(pNodo->pDerecha);
	}
}

void SbArbolRecorreInOrden(nodo_arbol *pNodo)
{
	if(pNodo == NULL)
		return;
	else
	{
		SbArbolRecorreInOrden(pNodo->pIzquierda);
		printf("%d \n", pNodo->iDato);
		SbArbolRecorreInOrden(pNodo->pDerecha);
	}
}

void SbArbolRecorrePostOrden(nodo_arbol *pNodo)
{
	if(pNodo == NULL)
		return;
	else
	{
		SbArbolRecorrePostOrden(pNodo->pIzquierda);
		SbArbolRecorrePostOrden(pNodo->pDerecha);
		printf("%d\n",pNodo->iDato);
	}
}


int main(int argc, char **argv)
{
	nodo_arbol *pRaiz = NULL;
	
	SbArbolInsertarNodo(&pRaiz,12);
	SbArbolInsertarNodo(&pRaiz,25);
	SbArbolInsertarNodo(&pRaiz,24);
	
	SbArbolRecorrePreOrden(pRaiz);
	SbArbolRecorreInOrden(pRaiz);
	SbArbolRecorrePostOrden(pRaiz);
	return 0;
}

