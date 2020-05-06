/*
 * Arbol_Binario_Expresion.c
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
	char cDato;
	struct NODO_ARBOL *pIzquierda;
	struct NODO_ARBOL *pDerecha;
}nodo_arbol;

nodo_arbol *FnArbolNodoCrea(char xDato)
{
	nodo_arbol *xNodo;
	
	xNodo = (nodo_arbol *)malloc(sizeof(nodo_arbol));
	
	if(xNodo == NULL)
		perror("Error.No se puede asignar memoria para el arbol");
	else
	{
		xNodo->cDato = xDato;
		xNodo->pDerecha = NULL;
		xNodo->pIzquierda = NULL;
	}
	return xNodo;
}

int FnBoolArbolInsertarNodo(nodo_arbol **pRaiz, char xDatoInsertar, char xDatoPadre, char cLado)
{
	nodo_arbol *pAuxiliar;
	
	if(*pRaiz == NULL)
	{
		nodo_arbol *pNodoNuevo;
		pNodoNuevo = FnArbolNodoCrea(xDatoInsertar);
		*pRaiz = pNodoNuevo;
		printf("Se inserto el dato %c como raiz del arbol\n", xDatoInsertar);
		return TRUE;
	}
	else
	{
		pAuxiliar = *pRaiz;
		if(pAuxiliar->cDato == xDatoPadre)
			if(cLado == 'D')
			{
				if(pAuxiliar->pDerecha == NULL)
				{
					nodo_arbol *pNodoNuevo;
					pNodoNuevo = FnArbolNodoCrea(xDatoInsertar);
					pAuxiliar->pDerecha = pNodoNuevo;
					printf("Inserto %c de lado derecha de %c\n", xDatoInsertar, xDatoPadre);
					return TRUE;
				}
			}
			else
			{
				if(pAuxiliar->pIzquierda == NULL)
				{
					nodo_arbol *pNodoNuevo;
					pNodoNuevo = FnArbolNodoCrea(xDatoInsertar);
					pAuxiliar->pIzquierda = pNodoNuevo;
					printf("Se inserto %c del lado izquierdo de %c\n", xDatoInsertar, xDatoPadre);
					return TRUE;
				}
			}
			if(pAuxiliar->pIzquierda != NULL)
				if(!FnBoolArbolInsertarNodo(&(pAuxiliar->pIzquierda),xDatoInsertar,xDatoPadre,cLado))
					if(pAuxiliar->pDerecha != NULL)
						if(!FnBoolArbolInsertarNodo(&(pAuxiliar->pDerecha),xDatoInsertar,xDatoPadre,cLado))
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


int main(int argc, char **argv)
{
	nodo_arbol *pRaiz = NULL;

    printf("Creando el arbol binario\n");

    FnBoolArbolInsertarNodo(&pRaiz,'*',' ', ' ');
    FnBoolArbolInsertarNodo(&pRaiz,'+','*', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'5','+', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'4','+', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'-','*', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'6','-', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'+','-', 'D');
    FnBoolArbolInsertarNodo(&pRaiz,'2','+', 'I');
    FnBoolArbolInsertarNodo(&pRaiz,'1','+', 'D');
	return 0;
}

