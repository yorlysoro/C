#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Cola {
	int elemento;
	struct Cola *ultimo;	
};

typedef struct Cola cola;

cola *Crear_Cola(int elemento);
int Cola_Vacia(cola *);
void Insertar(cola **, int elemento);
int Remover(cola **);
void Recorrer_Cola(cola *);
void Buscar(cola *, int elemento);

int main(void)
{
	cola *colas = NULL;
	
	Insertar(&colas,10);
	Insertar(&colas,11);
	Insertar(&colas,12);
	Insertar(&colas,33);
	Insertar(&colas,25);
	
	printf("Recorriendo la cola\n");
	Recorrer_Cola(colas);
	printf("Se remueve el elemento %d de la cola\n", Remover(&colas));
	printf("Recorriendo la cola\n");
	Recorrer_Cola(colas);
	Buscar(colas,33);
	Buscar(colas,10);
	return 0;
}

cola *Crear_Cola(int elemento)
{
	cola *NCola;
	NCola = (cola *)malloc(sizeof(cola));
	if(NCola == NULL)
	{
		perror("Error al crear la cola");
	}
	else
	{
		NCola->elemento = elemento;
		NCola->ultimo = NULL;
	}
	return NCola;
}

int Cola_Vacia(cola *ultimo)
{
	if(ultimo == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Insertar(cola **Primero, int elemento)
{
	cola *Nuevo_Elemento;
	cola *Aux_Elemento;
	
	Nuevo_Elemento = Crear_Cola(elemento);
	if(Cola_Vacia(*Primero))
	{
		*Primero = Nuevo_Elemento;
	}
	else
	{
		Aux_Elemento = *Primero;
		while(Aux_Elemento->ultimo != NULL)
		{
			Aux_Elemento = Aux_Elemento->ultimo;
		}
		Aux_Elemento->ultimo = Nuevo_Elemento;
	}
}

int Remover(cola **Primero)
{
	cola *ERemover;
	int dato;
	if(Cola_Vacia(*Primero))
	{
		printf("La cola esta vacia\n");
		return -1;
	}
	else
	{
		ERemover = *Primero;
		*Primero = (*Primero)->ultimo;
		dato = ERemover->elemento;
		free(ERemover);
	}
	return dato;
}

void Recorrer_Cola(cola *Primero)
{
	cola *Elementos;
	
	Elementos = Primero;
	while(Elementos != NULL)
	{
		printf("%d ", Elementos->elemento);
		Elementos = Elementos->ultimo;
	}
	puts("");
}

void Buscar(cola *Primero, int elemento)
{
	cola *Elementos;
	Elementos = Primero;
	while(Elementos != NULL)
	{
		if(Elementos->elemento == elemento)
		{
			printf("El elemento %d esta en la lista\n", Elementos->elemento);
			break;
		}
		Elementos = Elementos->ultimo;
	}
	if (Elementos == NULL)
	{
		printf("El elemento %d no esta en la lista\n", elemento);
	}
}

