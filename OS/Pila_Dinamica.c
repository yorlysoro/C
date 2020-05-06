#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Pila {
	int elemento;
	struct Pila *EAbajo;
};

typedef struct Pila pila;

pila *Crear_Pila(int elemento);
int Pila_Vacia(pila *);
void Push(pila **, int elemento );
int Pop(pila **);
void Recorrer(pila *);

int main(void){
	pila *pilas = NULL;
	
	Push(&pilas,10);
	Push(&pilas,5);
	Push(&pilas,9);
	Push(&pilas,11);
	Push(&pilas,20);
	Push(&pilas,35);
	
	printf("Recorriendo la pila\n");
	Recorrer(pilas);
	printf("Se extrae el elemento %d de la pila\n", Pop(&pilas));
	printf("Recorriendo la pila\n");
	Recorrer(pilas);
	
	return 0;
}

pila *Crear_Pila(int elemento)
{
	pila *Pilas;
	Pilas = (pila *)malloc(sizeof(pila));
	if(Pilas == NULL)
	{
		perror("Error al asignar memoria al nuevo dato");
	}
	else
	{
		Pilas->elemento = elemento;
		Pilas->EAbajo = NULL;
	}
	return Pilas;
}
int Pila_Vacia(pila *tope)
{
	if(tope== NULL)
		return true;
	else
		return false;
}
void Push(pila **Tope, int elemento)
{
	pila *aux_abajo;
	pila *ENuevo;
	ENuevo = Crear_Pila(elemento);
	if (Pila_Vacia(*Tope)){
		*Tope = ENuevo;
		(*Tope)->EAbajo = NULL;
	}
	else
	{
		aux_abajo = *Tope;
		*Tope = ENuevo;
		(*Tope)->EAbajo = aux_abajo;
	}
}

int Pop(pila **Tope)
{
	pila *ERemover;
	int dato;
	if(Pila_Vacia(*Tope))
	{
		printf("La pila esta vacia\n");
		return -1;
	}
	else
	{
		ERemover = *Tope;
		dato = ERemover->elemento;
		*Tope = (*Tope)->EAbajo;
		free(ERemover);
		return dato;
	}
}

void Recorrer(pila *Tope)
{
	pila *Elementos;
	Elementos = Tope;
	while(Elementos != NULL)
	{	
		printf("|%d|\n", Elementos->elemento);
		Elementos = Elementos->EAbajo;
	}	
}

