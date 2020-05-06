/*
 * Filas.c
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
	int iFilaFrente;
	int iFilaFinal;
	int arrIntFila[FILA_TAMANIO];
}fila;

void SbInicializaFila(fila *pFila)
{
	puts("Pila inicializada");
	pFila->iFilaFinal = -1;
	pFila->iFilaFrente = -1;
}
int FnIntFilaElementos(fila *pFila)
{
	return pFila->iFilaFinal+1;
}

int FnIntFilaVacia(fila *pFila)
{
	if(pFila->iFilaFinal==-1)
	return TRUE;
	else
	return FALSE;
}
int FnIntFilaLlena(fila *pFila)
{
	if(pFila->iFilaFinal+1 == FILA_TAMANIO)
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
void SbFilaInsertar(fila *pFila, int iElemento)
{
	if(FnIntFilaLlena(pFila))
		printf("La fila esta llena no se puede agregar el elemento %d\n", iElemento);
	else
	{
		if(pFila->iFilaFinal == -1)
			pFila->iFilaFrente = 0;
		pFila->arrIntFila[++pFila->iFilaFinal] = iElemento;
	}
}
void SbFilaRecorre(fila *pFila)
{
	int iIndice;
	for(iIndice = 1; iIndice <= pFila->iFilaFinal; iIndice++)
		pFila->arrIntFila[iIndice-1] = pFila->arrIntFila[iIndice];
	pFila->iFilaFinal--;
}
int FnIntFilaEliminar(fila *pFila)
{
	int iResult;
	if(FnIntFilaVacia(pFila))
	{
		puts("La fila esta vacia no se pueden sacar mas elementos\n");
		iResult = pFila->arrIntFila[pFila->iFilaFinal];
	}
	else
	{
		iResult = pFila->arrIntFila[pFila->iFilaFrente];
		if(pFila->iFilaFinal==0)
		{
			pFila->iFilaFinal = -1;
			pFila->iFilaFrente = -1;
		}
		else
			SbFilaRecorre(pFila);
	}
	return (iResult);
}


int main(int argc, char **argv)
{
	fila xFila;
	SbInicializaFila(&xFila);
	
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Agregramos el 10 a la fila\n\n ");
	 SbFilaInsertar(&xFila, 10);
	 
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el 16 a la fila\n");
	 
	 SbFilaInsertar(&xFila,16);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el 20 a la fila\n");
	 SbFilaInsertar(&xFila, 20);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el 60 a la fila\n");
	 SbFilaInsertar(&xFila, 60);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos dos elementos mas a la fila\n");
	 SbFilaInsertar(&xFila,25);
	 SbFilaInsertar(&xFila,55);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos del Frente de la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos del Frente de la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 putchar('\n');
	 
	return 0;
}

