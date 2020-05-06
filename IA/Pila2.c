/*
 * Pila2.c
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
typedef struct pila 
{
	int valor;
	struct pila *tope;
}tipopila;
typedef tipopila *Pila;
void Push(Pila *p,int dato)
{
	Pila nuevo;
	nuevo = (Pila)malloc(sizeof(tipopila));

	nuevo->valor = dato;
	nuevo->tope = *p;
	*p = nuevo; 
}
void Pop(Pila *p)
{
	Pila nodo;
	int valor;
	
	nodo = *p;
	
	if(!nodo)
		puts("La pila esta vacia");
	else
	{
		*p = nodo->tope;
		valor = nodo->valor;
		free(nodo);
		printf("El dato %d ha sido eliminado de la pila\n",valor);
	}
}
void Cima(Pila p)
{
	Pila cima;
	cima = p;
	
	printf("El elemento en la cima es %d\n", cima->valor);
}
int main(int argc, char **argv)
{
	Pila npila = NULL;
	
	Push(&npila,20);
	Push(&npila,30);
	Push(&npila,40);
	Push(&npila,50);
	Push(&npila,60);
	Cima(npila);
	Pop(&npila);
	Cima(npila);
	return 0;
}

