/*
 * Arboles_Binarios_Busqueda.c
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
		perror("Error.No se puede asignar memoria al nodo");
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
			printf("Se inserto el dato:%02d como hijo %s de:%02d en el nivel:%d\n",xDato, sLado,pAuxiliar->iDato,iNivel);
		else
			printf("Error,el dato %d ya existe como hijo:%d en el nivel %d\n",xDato,iPadre, --iNivel);
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
			if(FnBoolArbolBinarioBusquedaI(pNodo->pDerecha,xDato))
				return TRUE;
			else
				if(FnBoolArbolBinarioBusquedaI(pNodo->pIzquierda,xDato))
					return TRUE;
				else
					return FALSE;
}

int FnBoolArbolBinarioBusquedaII(nodo_arbol *pNodo,int xDato, int iNodoPadre, int iNivel, char cLado)
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
				printf("El dato %d fue encontrado en el nivel:%d\n", xDato,iNivel);
				if(iNivel == 0)
					printf("El dato %d no tiene padre, fue encontrado en la raiz del arbol\n", xDato);
				else
				{
					cLado == 'D' ? strcpy(strLado,"Der") : strcpy(strLado,"Izq");
					printf("El padre del dato es %d y es hijo %s\n", iNodoPadre,strLado);
				}
				return TRUE;
			}
			else
			{
				iNivel++;
				if(FnBoolArbolBinarioBusquedaII(pNodo->pDerecha,xDato,pNodo->iDato,iNivel,'D'))
					return TRUE;
				else
					if(FnBoolArbolBinarioBusquedaII(pNodo->pIzquierda,xDato,pNodo->iDato,iNivel,'I'))
						return TRUE;
					else
						return FALSE;
			}
}
int main(int argc, char **argv)
{
	nodo_arbol *pRaiz = NULL;
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
	/*	printf("Realizamos Busquedas simples\n");*/
/*	*/
/*	FnBoolArbolBinarioBusquedaI(pRaiz,17) ? printf("Si se encontro el 17\n") : printf("No se encontro el 17\n");*/
/*	*/
/*	FnBoolArbolBinarioBusquedaI(pRaiz,5) ? printf("Si se encontro el 5\n") : printf("No se encontro el 5\n");*/
/*	*/
/*	FnBoolArbolBinarioBusquedaI(pRaiz,10) ? printf("Si se encontro el 10\n") : printf("No se encontro el 10\n");*/
	
	printf("Realizamos Busquedas con Nivel, Padre y Lado\n");
	
	FnBoolArbolBinarioBusquedaII(pRaiz,10,-1,0,'R') ? printf("Se encontro el 10\n") : printf("No se encontro el 10\n");
	
	FnBoolArbolBinarioBusquedaII(pRaiz,27,-1,0,'R') ? printf("Se encontro el 27\n") : printf("No se encontro el 27\n");
	
	FnBoolArbolBinarioBusquedaII(pRaiz,100,-1,0,'R') ? printf("Se encontro el 100\n") : printf("No se encontro el 100\n");
	return 0;
}

