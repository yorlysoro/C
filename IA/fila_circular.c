/*
 * fila_circular.c
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
#define TRUE 1
#define FALSE 0
#define FILA_TAMANIO 5

typedef struct stcFila{
	int iFilaFinal;
	int iFilaFrente;
	int arrIntFila[FILA_TAMANIO];
}fila;

void SbInicializaFila(fila *pFila)
{
	puts("Pila inicializada");
	pFila->iFilaFinal = -1;
	pFila->iFilaFrente = -1;
}
int FnIntFilaVacia(fila *pFila)
{
	if(pFila->iFilaFinal==-1)
	return TRUE;
	else
	return FALSE;
}
int FnIntFilaFrente(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
	return(-1);
	else
	return pFila->arrIntFila[pFila->iFilaFrente];
}
int FnIntFilaFinal(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
	return (-1);
	else
	return pFila->arrIntFila[pFila->iFilaFinal];
}

int FnIntFilaCircularElementos(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
		return 0;
	else
		if(pFila->iFilaFinal>=pFila->iFilaFrente)
			return (pFila->iFilaFinal - pFila->iFilaFrente + 1);
		else
			return (FILA_TAMANIO - pFila->iFilaFrente + pFila->iFilaFinal + 1);
}

int FnIntFilaCircularLlena(fila *pFila)
{
	if(FnIntFilaCircularElementos(pFila) == FILA_TAMANIO)
		return TRUE;
	else
		return FALSE;
}
void SbFilaCircularInsertar(fila *pFila, int iElemento)
{
	if(FnIntFilaCircularLlena(pFila))
		printf("La fila esta llena no se pudo insertar %d\n", iElemento);
	else
	{
		if(pFila->iFilaFinal == -1)
		{
			pFila->iFilaFrente = 0;
			pFila->arrIntFila[++pFila->iFilaFinal] = iElemento;
		}
		else
			if(pFila->iFilaFinal + 1 == FILA_TAMANIO)
			{
				pFila->iFilaFinal = 0;
				pFila->arrIntFila[pFila->iFilaFinal] = iElemento;
			}
			else
				pFila->arrIntFila[++pFila->iFilaFinal] = iElemento;
	}
}

int FnIntFilaCircularEliminar(fila *pFila)
{
	int iResult;
	
	if(FnIntFilaVacia(pFila))
	{
		puts("La fila esta vacia no se pueden sacar mas elementos");
		iResult = -1;
	}
	else
	{
		iResult = pFila->arrIntFila[pFila->iFilaFrente];
		pFila->arrIntFila[pFila->iFilaFrente] = -1;
		
		if(pFila->iFilaFinal == pFila->iFilaFrente)
		{
			pFila->iFilaFinal = -1;
			pFila->iFilaFrente = -1;
		}
		else
			if(pFila->iFilaFrente + 1 == FILA_TAMANIO)
				pFila->iFilaFrente = 0;
			else
				pFila->iFilaFrente++;
	}
	return (iResult);
}

void SbFilaCircularDespliegaVector(fila *pFila)
{
	int iIndice;
	printf("Fila->| ");
	for(iIndice = 0; iIndice<FILA_TAMANIO; iIndice++)
		printf("%d | ", pFila->arrIntFila[iIndice]);
	putchar('\n');
}
int main(int argc, char **argv)
{
	fila xFila;
	
	xFila.arrIntFila[0]=-1;
	xFila.arrIntFila[1]=-1;
	xFila.arrIntFila[2]=-1;
	xFila.arrIntFila[3]=-1;
	xFila.arrIntFila[4]=-1;
	
	SbInicializaFila(&xFila);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	puts("Agregamos el elemento 10");
	SbFilaCircularInsertar(&xFila, 10);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos el elemento 13");
	SbFilaCircularInsertar(&xFila,13);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Vamos a agregar 5 elementos mas");
	SbFilaCircularInsertar(&xFila, 15);
	SbFilaCircularInsertar(&xFila, 25);
	SbFilaCircularInsertar(&xFila, 35);
	SbFilaCircularInsertar(&xFila, 45);
	SbFilaCircularInsertar(&xFila, 55);
	
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos 2 elementos mas");
	SbFilaCircularInsertar(&xFila,78);
	SbFilaCircularInsertar(&xFila,89);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos dos elementos mas en la fila");
	SbFilaCircularInsertar(&xFila, 89);
	SbFilaCircularInsertar(&xFila, 59);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos el elemento 96");
	SbFilaCircularInsertar(&xFila, 96);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	return 0;
}

