#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
	int elemento;
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
	return 0;
}

int Lista_Vacia(nodo *Primero)
{
	if(Primero == NULL)
		return true;
	else
		return false;
}

nodo *Crear_Nodo(int elemento)
{
	nodo *Nodo;
	
	Nodo = (nodo *)malloc(sizeof(nodo));
	
	if(Nodo == NULL)
	{
		perror("Error al asignar memoria al elemento");
		return NULL;
	}
	else
	{
		Nodo->elemento = elemento;
		Nodo->siguiente = NULL;
	}
	return Nodo;
}

void Insertar(nodo **Primero, int elemento)
{
	nodo *Nodo_Nuevo;
	nodo *Aux_Primero;
	Nodo_Nuevo = Crear_Nodo(elemento);
	if(Lista_Vacia(*Primero))
	{
		*Primero = Nodo_Nuevo;
	}
	else
	{
		Aux_Primero = *Primero;
		while(Aux_Primero->siguiente != NULL)
			Aux_Primero = Aux_Primero->siguiente;
		Aux_Primero->siguiente = Nodo_Nuevo;
	}
}

void Insertar_Inicio(nodo **Primero, int elemento)
{
	nodo *Nodo_Nuevo;
	Nodo_Nuevo = Crear_Nodo(elemento);
	if(Lista_Vacia(*Primero))
		*Primero = Nodo_Nuevo;
	else
	{
		Nodo_Nuevo->siguiente = *Primero;
		*Primero = Nodo_Nuevo;
	}
}
int Remover(nodo **Primero, int elemento)
{
	nodo *Nodo_Eliminar = NULL;
	nodo *Nodo_Anterior = NULL;
	int dato;
	if(Lista_Vacia(*Primero))
	{
		printf("La lista esta vacia\n");
	}
	else
	{
		if(elemento == (*Primero)->elemento)
		{
			Nodo_Eliminar = *Primero;
			*Primero = (*Primero)->siguiente;
			dato = Nodo_Eliminar->elemento;
			return dato;
		}
		else
		{
			Nodo_Eliminar = *Primero;
			Nodo_Anterior = *Primero;
			while(Nodo_Eliminar->siguiente != NULL)
			{
				if(Nodo_Anterior->siguiente->elemento != elemento)
					Nodo_Anterior = Nodo_Anterior->siguiente;
				if(Nodo_Eliminar->elemento == elemento)
					break;
				Nodo_Eliminar = Nodo_Eliminar->siguiente;
			}
			Nodo_Anterior->siguiente = Nodo_Eliminar->siguiente;
			dato = Nodo_Eliminar->elemento;
			free(Nodo_Eliminar);
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
	while(Elementos != NULL)
	{
		printf("%d ", Elementos->elemento);
		Elementos = Elementos->siguiente;
	}
	puts("");
}

void Buscar(nodo *Primero, int elemento)
{
	nodo *Elementos = Primero;
	while(Elementos != NULL)
	{
		if(Elementos->elemento == elemento)
		{
			printf("El elemento %d fue encontrado\n", Elementos->elemento);
			break;
		}
		Elementos = Elementos->siguiente;
	}
	if(Elementos == NULL)
		printf("Elemento %d no esta en la lista\n", elemento);
}
