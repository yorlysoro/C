#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
	int elemento;
	struct Nodo *anterior;
	struct Nodo *siguiente;
};

typedef struct Nodo nodo;

nodo *Crear_Nodo(int elemento);
void Insertar(nodo **, int elemento);
int Remover(nodo **, int elemento);
int Lista_Vacia(nodo *);
void Recorrer(nodo *);
void Insertar_Inicio(nodo **, int elemento);
void Buscar(nodo *, int elemento);
void Insertar_Despues_De(nodo **, int elemento, int index);

int main(void)
{
	nodo *Nodo = NULL;
	
	Insertar(&Nodo,10);
	Insertar(&Nodo,11);
	Insertar(&Nodo,12);
	Insertar(&Nodo,13);
	Insertar(&Nodo,14);
	Insertar(&Nodo,15);
	Insertar(&Nodo,16);
	Recorrer(Nodo);
	printf("Removiendo el %d\n", Remover(&Nodo,10));
	printf("Removiendo el %d\n", Remover(&Nodo,16));
	printf("Removiendo el %d\n", Remover(&Nodo,13));
	Recorrer(Nodo);
	Insertar_Inicio(&Nodo,20);
	Recorrer(Nodo);
	Buscar(Nodo,12);
	Buscar(Nodo,13);
	Insertar_Despues_De(&Nodo,25,12);
	Insertar_Despues_De(&Nodo,18, 20);
	Insertar_Despues_De(&Nodo,64,15);
	Recorrer(Nodo);
	return 0;
}

int Lista_Vacia(nodo *Primero)
{
	if(Primero == NULL)
		return true;
	else
		return false;
}

nodo *Crear_Nodo( int elemento)
{
	nodo *Nodo_Nuevo;
	Nodo_Nuevo = (nodo *)malloc(sizeof(nodo));
	if(Nodo_Nuevo == NULL)
	{
		perror("No se pudo asignar memoria");
	}
	else
	{
		Nodo_Nuevo->elemento = elemento;
		Nodo_Nuevo->siguiente = NULL;
		Nodo_Nuevo->anterior = NULL;
	}
	return Nodo_Nuevo;
}

void Insertar(nodo **Primero, int elemento)
{
	nodo *Nodo_Nuevo = NULL;
	nodo *Aux_Primero = NULL;
	Nodo_Nuevo = Crear_Nodo(elemento);
	if(Lista_Vacia(*Primero))
	{
		(*Primero) = Nodo_Nuevo;
		(*Primero)->siguiente = Nodo_Nuevo;
		(*Primero)->anterior = Nodo_Nuevo;
	}
	else
	{
		Aux_Primero = *Primero;
		while(Aux_Primero->siguiente != *Primero)
			Aux_Primero = Aux_Primero->siguiente;
		Nodo_Nuevo->anterior = Aux_Primero;
		Nodo_Nuevo->siguiente = *Primero;
		(*Primero)->anterior = Nodo_Nuevo;
		Aux_Primero->siguiente = Nodo_Nuevo;
	}
}

int Remover(nodo **Primero, int elemento)
{
	nodo *Aux_Primero = NULL;
	int dato;
	if(Lista_Vacia(*Primero))
	{
		printf("Lista Vacia\n");
		return -1;
	}
	else
	{
		if((*Primero)->siguiente == *Primero)
		{
			free(Primero);
		}
		else if((*Primero)->elemento == elemento)
		{
			dato = (*Primero)->elemento;
			(*Primero)->siguiente->anterior = (*Primero)->anterior;
			(*Primero)->anterior->siguiente = (*Primero)->siguiente;
			(*Primero) = (*Primero)->siguiente;
			return dato;
		}
		else
		{		
			Aux_Primero = *Primero;
			while(Aux_Primero->siguiente != *Primero)
			{
				if(Aux_Primero->elemento == elemento)
					break;
				Aux_Primero = Aux_Primero->siguiente;
			}
			dato = Aux_Primero->elemento;
			Aux_Primero->anterior->siguiente = Aux_Primero->siguiente;
			Aux_Primero->siguiente->anterior = Aux_Primero->anterior;
			Aux_Primero->anterior = NULL;
			Aux_Primero->siguiente = NULL;
			Aux_Primero = NULL;
			free(Aux_Primero);
			return dato;
		}
	}
	return 0;
}

void Recorrer(nodo *Primero)
{
	nodo *Elementos;
	Elementos = Primero;
	puts("Recorriendo la lista");
	while(true)
	{
		printf("%d <- %d -> %d\n", Elementos->anterior->elemento,Elementos->elemento,Elementos->siguiente->elemento);
		Elementos = Elementos->siguiente;
		if(Elementos == Primero)
			break;
	}
	puts("");
}

void Insertar_Inicio(nodo **Primero, int elemento)
{
	nodo *Nodo_Nuevo = NULL;
	Nodo_Nuevo = Crear_Nodo(elemento);
	if(Lista_Vacia(*Primero))
	{
		(*Primero) = Nodo_Nuevo;
		(*Primero)->siguiente = Nodo_Nuevo;
		(*Primero)->anterior = Nodo_Nuevo;
	}
	else
	{
		Nodo_Nuevo->siguiente = *Primero;
		Nodo_Nuevo->anterior = (*Primero)->anterior;
		(*Primero)->anterior->siguiente = Nodo_Nuevo;
		(*Primero)->anterior = Nodo_Nuevo;
		*Primero = Nodo_Nuevo;
	}
}

void Buscar(nodo *Primero, int elemento)
{
	nodo *Elementos = Primero;
	while(true)
	{
		if(Elementos->elemento == elemento)
		{
			printf("El elemento %d fue encontrado\n", Elementos->elemento);
			break;
		}
		Elementos = Elementos->siguiente;
		if(Elementos->siguiente == Primero)
			break;
	}
	if(Elementos->siguiente == Primero)
		printf("Elemento %d no esta en la lista\n", elemento);
	puts("");
}

void Insertar_Despues_De(nodo **Primero, int elemento, int index)
{
	nodo *Nodo_Nuevo = NULL;
	nodo *Aux_Primero = NULL;
	if((*Primero)->elemento == index)
		Insertar_Inicio(Primero, elemento);
	else if((*Primero)->anterior->elemento == index)
		Insertar(Primero, elemento);
	else
	{
		Aux_Primero = *Primero;
		while(true)
		{
			if(Aux_Primero->elemento == index)
				break;
			Aux_Primero = Aux_Primero->siguiente;
		}
		Nodo_Nuevo = Crear_Nodo(elemento);
		Nodo_Nuevo->siguiente = Aux_Primero->siguiente;
		Nodo_Nuevo->anterior = Aux_Primero;
		Aux_Primero->siguiente->anterior = Nodo_Nuevo;
		Aux_Primero->siguiente = Nodo_Nuevo;
	}
}
