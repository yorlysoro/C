/*
 * Arbol_AVL.c
 *
 * Copyright 2017 copyleft <copyleft@debian>
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
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Raiz{
	int elemento;
	struct Raiz *izquierda;
	struct Raiz *derecha;
	struct Raiz *padre;
	int FE;
};

typedef struct Raiz raiz;

raiz *Crear_Raiz(int);
void Insertar(raiz **, int);
void Equilibrar(raiz **, raiz *, char[3], int);
void RDD(raiz *);
void RDI(raiz **, raiz *);
void RSD(raiz **, raiz *);
void RSI(raiz **, raiz *);
int Es_Hoja(raiz *);
void Eliminar(raiz **, int);
void Recorrer(raiz *, char*, raiz *);

int main(void)
{
	raiz *Raiz = NULL;
	Insertar(&Raiz,8);
	Insertar(&Raiz,2);
	Insertar(&Raiz,4);
	Insertar(&Raiz,10);
	Insertar(&Raiz,9);
	Insertar(&Raiz,12);
	Insertar(&Raiz,14);
	puts("Se muestra el arbol");
	Recorrer(Raiz,"Rai",Raiz);
	puts("Se elimina un elemento");
	Eliminar(&Raiz,9);
	puts("El arbol despues de eliminar");
	Recorrer(Raiz,"Rai", Raiz);
	return 0;
}

raiz *Crear_Raiz(int elemento)
{
	raiz *Nueva_Raiz = NULL;

	Nueva_Raiz = (raiz *)malloc(sizeof(raiz));

	if (Nueva_Raiz == NULL)
		perror("Error al asignar memoria, ");
	else
	{
		Nueva_Raiz->elemento = elemento;
		Nueva_Raiz->izquierda = NULL;
		Nueva_Raiz->derecha = NULL;
		Nueva_Raiz->padre = NULL;
		Nueva_Raiz->FE = 0;
	}
	return Nueva_Raiz;
}

void Insertar(raiz **Raiz, int elemento)
{
	raiz *Padre = NULL;
	raiz *Actual = *Raiz;

	while(Actual != NULL && elemento != Actual->elemento)
	{
		Padre = Actual;
		if(elemento < Actual->elemento)
			Actual = Actual->izquierda;
		else if(elemento > Actual->elemento)
			Actual = Actual->derecha;
	}
	if(Actual != NULL)
		return;
	if(Padre == NULL)
		*Raiz = Crear_Raiz(elemento);
	else if(elemento < Padre->elemento)
	{
		Actual = Crear_Raiz(elemento);
		Padre->izquierda = Actual;
		Actual->padre = Padre;
		Equilibrar(&(*Raiz),Padre, "Izq", true);
	}
	else if(elemento > Padre->elemento)
	{
		Actual = Crear_Raiz(elemento);
		Padre->derecha = Actual;
		Actual->padre = Padre;
		Equilibrar(&(*Raiz),Padre,"Der", true);
	}
}

void Equilibrar(raiz **Raiz, raiz *Padre, char *Rama, int boolean)
{
	int Salir = false;
	while(Padre != NULL && Salir != true)
	{
		if(boolean)
		{
			if(strcmp(Rama, "Izq") == 0)
				Padre->FE -= 1;
			else
				Padre->FE += 1;
		}
		else
		{
			if(strcmp(Rama, "Izq") == 0)
				Padre->FE += 1;
			else
				Padre->FE -= 1;
		}
		if (Padre->FE == 0)
		{
            Salir = true;
		}
		else if(Padre->FE == -2)
		{
            if(Padre->izquierda->FE == 1)
                RDD(Padre);
            else
                RSD(&(*Raiz), Padre);
            Salir = true;
        }
        else if(Padre->FE == 2)
        {
            if(Padre->derecha->FE == -1)
                RDI(&(*Raiz), Padre);
            else
                RSI(&(*Raiz), Padre);
            Salir = true;
        }
        if(Padre->padre)
        {
            if(Padre->padre->derecha == Padre)
                Rama = "Der";
            else
                Rama = "Izq";
        }
	}
}

void RDD(raiz *Padre)
{
	raiz *padre = Padre->padre;
	raiz *A = Padre;
	raiz *B = A->izquierda;
	raiz *C = B->derecha;
	raiz *CI = C->izquierda;
	raiz *CD = C->derecha;
	if(padre)
	{
		if(padre->derecha == A)
			padre->derecha = C;
		else
			padre->izquierda = C;
	}
	else
		Padre = C;
	B->derecha = CI;
	A->izquierda = CD;
	C->izquierda = B;
	C->derecha = A;
	C->padre = padre;
	A->padre = B->padre = C;
	if(CI)
		CI->padre = B;
	if(CD)
		CD->padre = A;
	switch(C->FE)
	{
		case -1:
			B->FE = 0;
			A->FE = 1;
			break;
		case 0:
			B->FE = 0;
			A->FE = 0;
		case 1:
			B->FE = -1;
			A->FE = 0;
	}
	C->FE = 0;
}

void RDI(raiz **Raiz, raiz *Padre)
{
	raiz *padre = Padre->padre;
	raiz *A = Padre;
	raiz *B = A->derecha;
	raiz *C = B->izquierda;
	raiz *CI = C->izquierda;
	raiz *CD = C->derecha;
	
	if (padre)
		if(padre->derecha == A)
			padre->derecha = C;
		else
			padre->izquierda = C;
	else
		*Raiz = C;
	A->derecha = CI;
	B->izquierda = CD;
	C->izquierda = A;
	C->derecha = B;
	C->padre = padre;
	A->padre = B->padre = C;
	if(CI)
		CI->padre = A;
	if(CD)
		CD->padre = B;
	switch(C->FE)
	{
		case -1:
			A->FE = 0;
			B->FE = 1;
			break;
		case 0:
			A->FE = 0;
			B->FE = 0;;
		case 1:
			A->FE = -1;
			B->FE = 0;
	}
	C->FE = 0;
}

void RSD(raiz **Raiz, raiz *Padre)
{
	raiz *padre = Padre->padre;
	raiz *A = Padre;
	raiz *B = A->izquierda;
	raiz *C = B->derecha;
	if(padre)
		if(padre->derecha == A)
			padre->derecha = B;
		else
			padre->izquierda = B;
	else
		*Raiz = B;
	A->izquierda = C;
	B->derecha = A;
	A->padre = B;
	if(C)
		C->padre = A;
	B->padre = Padre;
	A->FE = 0;
	B->FE = 0;
}

void RSI(raiz **Raiz, raiz *Padre)
{
	raiz *padre = Padre->padre;
	raiz *A = Padre;
	raiz *B = A->derecha;
	raiz *C = B->derecha;
	if(padre)
		if(padre->derecha == A)
			padre->derecha = B;
		else
			padre->izquierda = B;
	else
		*Raiz = B;
	A->derecha = C;
	B->izquierda = A;
	A->padre = B;
	if(C)
		C->padre = A;
	B->padre = padre;
	A->FE = 0;
	B->FE = 0;
}

int Es_Hoja(raiz *Nodo)
{
	if(!Nodo->derecha && !Nodo->izquierda)
		return true;
	else
		return false;
}

void Eliminar(raiz **Raiz, int elemento)
{
	raiz *Padre = NULL;
	raiz *Actual = *Raiz;
	raiz *Nodo = NULL;
	int Aux = 0;
	while(Actual != NULL)
	{
		if(elemento == Actual->elemento)
		{
			if(Es_Hoja(Actual))
			{
				if(Padre)
				{
					if(Padre->derecha == Actual)
						Padre->derecha = NULL;
					else if(Padre->izquierda == Actual)
						Padre->izquierda = NULL;
				}
				free(Actual);
				Actual = NULL;
				if((Padre->derecha == Actual && Padre->FE == 1) || (Padre->izquierda == Actual && Padre->FE == 1))
				{
					Padre->FE = 0;
					Actual = Padre;
					Padre = Actual->padre;
				}
				if(Padre)
				{
					if(Padre->derecha == Actual)
						Equilibrar(&(*Raiz),Padre, "Der", false);
					else
						Equilibrar(&(*Raiz),Padre,"Izq", false);
				}
			}
			else
			{
				Padre = Actual;
				if(Actual->derecha)
				{
					Nodo = Actual->derecha;
					while(Nodo->izquierda)
					{
						Padre = Nodo;
						Nodo = Nodo->izquierda;
					}
				}
				else
				{
					Nodo = Actual->izquierda;
					while(Nodo->derecha)
					{
						Padre = Nodo;
						Nodo = Nodo->derecha;
					}
				}
			}
			Aux = Actual->elemento;
			Actual->elemento = Nodo->elemento;
			Nodo->elemento = Aux;
			Actual = Nodo;
		}
		else
		{
			Padre = Actual;
			if(elemento > Actual->elemento)
				Actual = Actual->derecha;
			else if(elemento < Actual->elemento)
				Actual= Actual->izquierda;
		}
	}
}

void Recorrer(raiz *Raiz, char Lado[3], raiz *Padre)
{
	if(Raiz == NULL)
		return;
	else
	{
		printf("%d como hijo de %d por la %s\n", Raiz->elemento,Padre->elemento, Lado);
		Recorrer(Raiz->izquierda, "Izq", Raiz);
		Recorrer(Raiz->derecha, "Der", Raiz);
	}
}
