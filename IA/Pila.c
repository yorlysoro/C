/*
 * Pila.c
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
typedef struct _nodo{
	int valor;
	struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

void Push(Pila *p, int dato);
void Pop(Pila *p);
void Cima(Pila p);
int main(int argc, char **argv)
{
	Pila pila = NULL;
	
	Push(&pila,20);
	Push(&pila,30);
	Cima(pila);
	Pop(&pila);
	Cima(pila);
	return 0;
}

void Push(Pila *p, int dato)
{
	pNodo nuevo;
	
	nuevo = (pNodo)malloc(sizeof(tipoNodo));
	nuevo->valor = dato;
	
	nuevo->siguiente = *p;
	*p = nuevo;
}

void Pop(Pila *p)
{
	pNodo nodo;
	int valor;
	
	nodo = *p;
	if(!nodo)
		puts("La pila esta vacia");
	else
	{
		*p = nodo->siguiente;
		valor = nodo->valor;
		free(nodo);
		printf("Se elemino el valor %d de la pila\n", valor);
	}	
}

void Cima(Pila p)
{
	pNodo cima;
	cima = (pNodo)malloc(sizeof(tipoNodo));
	cima = p;
	printf("El elemento en la cima es %d\n", cima->valor );
}
