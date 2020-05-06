/*
 * Filas2.c
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
int FnIntFilaElementosII(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
	return 0;
	else
	return pFila->iFilaFinal-pFila->iFilaFrente+1;
}
int FnIntFilaLlenaII(fila *pFila)
{
	if(FnIntFilaElementosII(pFila) == FILA_TAMANIO)
	return TRUE;
	else
	return FALSE;
}
void SbFilaRecorreII(fila *pFila)
{
	int iIndice1;
	int iIndice2;
	
	for(iIndice1 = 0, iIndice2 = pFila->iFilaFrente; iIndice2<= pFila->iFilaFinal; iIndice1++, iIndice2++)
		pFila->arrIntFila[iIndice1] = pFila->arrIntFila[iIndice2];
		
	pFila->iFilaFinal = pFila->iFilaFinal - pFila->iFilaFrente;
	
	pFila->iFilaFrente = 0;
}
void SbFilaInsertarII(fila *pFila, int iElemento)
{
	if(FnIntFilaLlenaII(pFila))
	printf("La fila esta llena no se puede agregar el elemento %d a la fila\n", iElemento);
	else
	{
		if(pFila->iFilaFinal == -1)
			pFila->iFilaFrente = 0;
		else
			if(pFila->iFilaFinal+1==FILA_TAMANIO)
				SbFilaRecorreII(pFila);
		pFila->arrIntFila[++pFila->iFilaFinal] = iElemento;
	}
}
int FnIntFilaEliminarII(fila *pFila)
{
	int iResult;
	if(FnIntFilaVacia(pFila))
	{
		puts("La fila esta vacia no se puede sacar mas elementos");
		iResult = -1;
	}
	else
	{
		iResult = pFila->arrIntFila[pFila->iFilaFrente];
		if(pFila->iFilaFinal == pFila->iFilaFrente)
		{
			pFila->iFilaFinal = -1;
			pFila->iFilaFrente = -1;
		}
		else
			pFila->iFilaFrente++;
	}
	return iResult;
}
int main(void)
{
	fila xFila;
	
	SbInicializaFila(&xFila);
	
	 printf("Elementos en la fila %d\n", FnIntFilaElementosII(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlenaII(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el elemento 16 a la fila\n");
	 SbFilaInsertarII(&xFila,16);
	 printf("Elementos en la fila %d\n", FnIntFilaElementosII(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlenaII(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el elemento 20 a la fila\n");
	 SbFilaInsertarII(&xFila,20);
	 printf("Elementos en la fila %d\n", FnIntFilaElementosII(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlenaII(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos los elementos 30,40,50,60 a la fila\n");
	 SbFilaInsertarII(&xFila,30);
	 SbFilaInsertarII(&xFila,40);
	 SbFilaInsertarII(&xFila,50);
	 SbFilaInsertarII(&xFila,60);
	 printf("Elementos en la fila %d\n", FnIntFilaElementosII(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlenaII(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos el elemento %d de la fila\n", FnIntFilaEliminarII(&xFila));
	 printf("Elementos en la fila %d\n", FnIntFilaElementosII(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlenaII(&xFila) ? "TRUE" : "FALSE");
	 printf("Eliminamos el elemento %d de la fila\n", FnIntFilaEliminarII(&xFila));
	 printf("Elementos en la fila %d\n", FnIntFilaElementosII(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlenaII(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos el elemento %d de la fila\n", FnIntFilaEliminarII(&xFila));
	 printf("Eliminamos el elemento %d de la fila\n", FnIntFilaEliminarII(&xFila));
	 printf("Eliminamos el elemento %d de la fila\n", FnIntFilaEliminarII(&xFila));
	 printf("Eliminamos el elemento %d de la fila\n", FnIntFilaEliminarII(&xFila));
	 printf("Elementos en la fila %d\n", FnIntFilaElementosII(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlenaII(&xFila) ? "TRUE" : "FALSE");
	 
	return 0;
}

