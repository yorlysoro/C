#include <stdio.h>
#include "Filas-2.h"


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
