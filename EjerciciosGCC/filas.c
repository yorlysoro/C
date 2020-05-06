#include <stdio.h>
#include "filas.h"


int main(void)
		
{
	 fila xFila;
	 SbInicializaFila(&xFila);
	 
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Agregramos el 10 a la fila\n\n ");
	 SbFilaInsertar(&xFila, 10);
	 
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el 16 a la fila\n");
	 
	 SbFilaInsertar(&xFila,16);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el 20 a la fila\n");
	 SbFilaInsertar(&xFila, 20);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos el 60 a la fila\n");
	 SbFilaInsertar(&xFila, 60);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 puts("Agregamos dos elementos mas a la fila\n");
	 SbFilaInsertar(&xFila,25);
	 SbFilaInsertar(&xFila,55);
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos del Frente de la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos del Frente de la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 printf("Eliminamos del frente del la fila al elemento: %d\n", FnIntFilaEliminar(&xFila));
	 
	 printf("Elementos en la fila %d\n", FnIntFilaElementos(&xFila));
	 printf("El frente de la fila: %d\n", FnIntFilaFrente(&xFila));
	 printf("El final de la fila es %d\n", FnIntFilaFinal(&xFila));
	 printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	 printf("La fila esta llena: %s\n\n", FnIntFilaLlena(&xFila) ? "TRUE" : "FALSE");
	 putchar('\n');
	 
	 return 0;
}
