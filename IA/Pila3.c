/*
 * Pila3.c
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
#define TRUE 1
#define FALSE 0
#define PILA_TAMANIO 5
#define LN putchar('\n');

typedef struct
{
	int iPilaTope;
	int arrIntPila[PILA_TAMANIO];
}pila;

void SbPilaInicializa(pila *pPila)
{
	pPila->iPilaTope = -1;
	puts("Pila inicializada");
}

int FnIntPilaVacia(pila *pPila)
{
	if(pPila->iPilaTope==-1)
	return TRUE;
	else
	return FALSE;
}
int FnIntPilaLlena(pila *pPila)
{
	if(pPila->iPilaTope==PILA_TAMANIO-1)
	return TRUE;
	else
	return FALSE;
}
int FnIntPilaElementos(pila *pPila)
{
	return pPila->iPilaTope+1;
}
void SbPilaCima(pila *pPila)
{
	if(FnIntPilaVacia(pPila))
	puts("La pila esta vacia no hay elementos en la cima");
	else
	printf("Pila cima: %d\n", pPila->arrIntPila[pPila->iPilaTope]);
}
void SbPilaPush(pila *pPila, int iElemento)
{
	if(FnIntPilaLlena(pPila))
	printf("La pila esta llena no se puede agregar el elemento %d\n", iElemento);
	else
	{
		pPila->iPilaTope++;
		pPila->arrIntPila[pPila->iPilaTope] = iElemento;
		printf("Se ha agregado el elemento %d a la pila\n", iElemento);
	}
}
int FnIntPilaPop(pila *pPila)
{
	if(FnIntPilaVacia(pPila))
	{
		puts("La pila esta vacia no se pueden sacar mas elementos");
		return pPila->iPilaTope;
	}
	else
	{
		puts("Se ha sacado un elemento de la pila");
		return(pPila->arrIntPila[pPila->iPilaTope--]);
	}
}
int main(int argc, char **argv)
{
	pila xPila;
	
	int iElemento;
	
	SbPilaInicializa(&xPila);
	FnIntPilaVacia(&xPila) ? printf("La pila si esta vacia\n") : printf("La pila no esta vacia\n");
	FnIntPilaLlena(&xPila) ? puts("La pila si esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaElementos(&xPila));
	SbPilaCima(&xPila);
	LN
	SbPilaPush(&xPila,34);
	SbPilaPush(&xPila,25);
	FnIntPilaVacia(&xPila) ? puts("La pila esta vacia") : puts("La pila no esta vacia");
	FnIntPilaLlena(&xPila) ? puts("La pila esta llena") : puts("La pila no esta llena");
	printf("Elementos en la pila: %d\n", FnIntPilaElementos(&xPila));
	LN
	return 0;
}

