#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Arbol {
	int elemento;
	struct Arbol *izquierda;
	struct Arbol *derecha;
};

typedef struct Arbol raiz;

raiz *Crear_Raiz(int elemento);
void Insertar(raiz **, int elemento);
void PreOrden(raiz *);
void InOrden(raiz *);
void PostOrden(raiz *);
int Nodos(raiz *);
int Altura(raiz *, int nivel);
int Eliminar(raiz **, int elemento);
int Busqueda(raiz *, int elemento);
int BusquedaII(raiz *, int elemento, int Padre, int nivel, char []);

int main(void)
{
	raiz *Raiz = NULL;
	
	Insertar(&Raiz,10);
	Insertar(&Raiz,9);
	Insertar(&Raiz,11);
	Insertar(&Raiz,13);
	Insertar(&Raiz,2);
	Insertar(&Raiz,4);
	Insertar(&Raiz,12);
	Insertar(&Raiz,14);
	puts("Recorriendo el arbol en PreOrden");
	PreOrden(Raiz);
	puts("");
	puts("Recorriendo el arbol en InOrden");
	InOrden(Raiz);
	puts("");
	puts("Recorriendo el arbol en PostOrden");
	PostOrden(Raiz);
	puts("");
	printf("El arbol contiene %d nodos\n", Nodos(Raiz));
	printf("La altura del arbol es %d\n", Altura(Raiz,1));
	puts("Eliminando un elemento");
	Eliminar(&Raiz,13);
	puts("Recorriendo el arbol en InOrden");
	InOrden(Raiz);
	puts("");
	printf("El arbol contiene %d nodos\n", Nodos(Raiz));
	printf("La altura del arbol es %d\n", Altura(Raiz,1));
	puts("Eliminando un elemento");
	Eliminar(&Raiz,2);
	puts("Recorriendo el arbol en InOrden");
	InOrden(Raiz);
	puts("");
	puts("Eliminando un elemento"); 
	Eliminar(&Raiz,9);
	puts("Recorriendo el arbol en InOrden");
	InOrden(Raiz);
	puts("");
	printf("El arbol contiene %d nodos\n", Nodos(Raiz));
	printf("La altura del arbol es %d\n", Altura(Raiz,1));
	if(Busqueda(Raiz,14))
		puts("Esta en el arbol");
	else
		puts("No esta en el arbol");
	BusquedaII(Raiz,14,Raiz->elemento,1,"Der");

	return 0;
}

raiz *Crear_Raiz(int elemento)
{
	raiz *Nueva_Raiz = NULL;
	
	Nueva_Raiz = (raiz *)malloc(sizeof(raiz));
	if(Nueva_Raiz == NULL)
		perror("Error a asignar memoria a la nueva raiz");
	else
	{
		Nueva_Raiz->elemento = elemento;
		Nueva_Raiz->izquierda = NULL;
		Nueva_Raiz->derecha = NULL;
	}
	return Nueva_Raiz;
}

void Insertar(raiz **Raiz, int elemento)
{
	raiz *Nueva_Raiz = NULL;
	raiz *Aux_Raiz = NULL;
	
	Nueva_Raiz = Crear_Raiz(elemento);
	int nivel, padre, result;
	char lado[3];
	
	if(*Raiz == NULL)
	{
		*Raiz = Nueva_Raiz;
		printf("Se inserto %d como raiz del arbol\n", elemento);
	}
	else
	{
		nivel = padre = 0;
		result = true;
		Aux_Raiz = *Raiz;
		while(true)
		{
			nivel += 1;
			if(Aux_Raiz->elemento < elemento)
			{
				if(Aux_Raiz->derecha != NULL)
				{
					padre = Aux_Raiz->elemento;
					Aux_Raiz = Aux_Raiz->derecha;
				}
				else
				{
					Aux_Raiz->derecha = Nueva_Raiz;
					strcpy(lado,"Der");
					break;
				}
			}
			else if(Aux_Raiz->elemento > elemento)
			{
				if(Aux_Raiz->izquierda != NULL)
				{
					padre = Aux_Raiz->elemento;
					Aux_Raiz = Aux_Raiz->izquierda;
				}
				else
				{
					Aux_Raiz->izquierda = Nueva_Raiz;
					strcpy(lado, "Izq");
					break;
				}
			}
			else
			{
				result = false;
				break;
			}
		}
		if(result)
			printf("Se inserto el dato %d como hijo %s de %d en el nivel %d\n", elemento, lado, Aux_Raiz->elemento, nivel);
		else
			printf("El dato %d existe como hijo de %d en el nivel %d", elemento, padre, nivel-1);
	}
}

void PreOrden(raiz *Raiz)
{
	if(Raiz == NULL)
		return;
	else
	{
		printf("%d ", Raiz->elemento);
		PreOrden(Raiz->izquierda);
		PreOrden(Raiz->derecha);
	}
}

void InOrden(raiz *Raiz)
{
	if(Raiz == NULL)
		return;
	else
	{
		InOrden(Raiz->izquierda);
		printf("%d ", Raiz->elemento);
		InOrden(Raiz->derecha);
	}
}

void PostOrden(raiz *Raiz)
{
	if(Raiz == NULL)
		return;
	else
	{
		PostOrden(Raiz->izquierda);
		PostOrden(Raiz->derecha);
		printf("%d ", Raiz->elemento);
	}
}

int Nodos(raiz *Raiz)
{
	int izquierdos, derechos;
	if(Raiz == NULL)
		return 0;
	else
	{
		izquierdos = Nodos(Raiz->izquierda);
		derechos = Nodos(Raiz->derecha);
		return 1 + izquierdos + derechos;
	}
}

int Altura(raiz *Raiz, int nivel)
{
	int Altura1, Altura2;
	if(Raiz == NULL)
		return 0;
	else
	{
		Altura1 = Altura(Raiz->izquierda, nivel+1);
		Altura2 = Altura(Raiz->derecha, nivel+1);
		if(Altura1 >= Altura2 && Altura1 >= nivel)
			return Altura1;
		else if(Altura2 >= Altura1 && Altura2 >= nivel)
			return Altura2;
		else
			return nivel;
	}
}

int Eliminar(raiz **Raiz, int elemento)
{
	raiz *Raiz_Eliminar = NULL;
	raiz *RaizAuxActual = NULL;
	raiz *RaizAuxPadre = NULL;
	
	if(*Raiz == NULL)
		return false;
	else
	{
		printf("Nodo Actual %d\n", (*Raiz)->elemento);
		if((*Raiz)->elemento == elemento)
		{
			puts("Es el nodo a eliminar");
			if((*Raiz)->derecha == NULL && (*Raiz)->izquierda == NULL)
			{
				printf("Se elimino un nodo hoja %d\n", (*Raiz)->elemento);
				*Raiz = NULL;
				free(Raiz);
			}
			else
			{
				if((*Raiz)->izquierda == NULL)
				{
					printf("Tiene un solo hijo, el derecho %d\n",(*Raiz)->derecha->elemento);
					printf("El nodo derecha %d ocupa su lugar\n",(*Raiz)->derecha->elemento);
					Raiz_Eliminar = (*Raiz);
					(*Raiz) = (*Raiz)->derecha;
					free(Raiz_Eliminar);
					return true;
				}
				else
				{
					if((*Raiz)->derecha == NULL)
					{
						printf("Tiene un solo hijo, el izquierdo %d\n", (*Raiz)->izquierda->elemento);
						printf("El nodo izquierda %d ocupa su lugar\n", (*Raiz)->izquierda->elemento);
						Raiz_Eliminar = (*Raiz);
						(*Raiz) = (*Raiz)->izquierda;
						free(Raiz_Eliminar);
						return true;
					}
					else
					{
						puts("El nodo a eliminar tiene dos hijos");
						RaizAuxPadre = *Raiz;
						RaizAuxActual = (*Raiz)->derecha;
						while(RaizAuxActual->izquierda != NULL)
						{
							RaizAuxPadre = RaizAuxActual;
							RaizAuxActual = RaizAuxActual->izquierda;
						}
						(*Raiz)->elemento = RaizAuxActual->elemento;
						if(RaizAuxPadre == *Raiz)
							RaizAuxPadre->derecha = RaizAuxActual->derecha;
						else
							RaizAuxPadre->izquierda = RaizAuxActual->derecha;
						free(RaizAuxActual);
						return true;
					}
				}
			}
		}
		else
		{
			if((*Raiz)->elemento < elemento)
				Eliminar(&(*Raiz)->derecha, elemento);
			else
				Eliminar(&(*Raiz)->izquierda, elemento);
		}
		return true;
	}
	return false;

}

int Busqueda(raiz *Raiz, int elemento)
{
	if(Raiz == NULL)
		return false;
	else if(Raiz->elemento == elemento)
		return true;
	else if(Busqueda(Raiz->derecha, elemento))
		return true;
	else if(Busqueda(Raiz->izquierda, elemento))
		return true;
	else
		return false;
}

int BusquedaII(raiz *Raiz, int elemento, int Padre, int nivel, char Lado[3])
{
	if(Raiz == NULL && nivel == 0)
		return false;
	else
	{
		if(Raiz == NULL)
			return false;
		else if(Raiz->elemento == elemento)
		{
			printf("El elemento %d fue encontrado\n", elemento);
			if(nivel == 0)
				printf("El elemento es la raiz del arbol\n");
			else
				printf("Se encuentra a la %s de %d\n", Lado, Padre);
			return true;
		}
		else
		{
			nivel += 1;
			if(BusquedaII(Raiz->derecha, elemento, Raiz->elemento, nivel, "Der"))
			{
				return true;
			}
			else if (BusquedaII(Raiz->izquierda, elemento, Raiz->elemento, nivel, "Izq"))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
