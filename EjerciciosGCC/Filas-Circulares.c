#include <stdio.h>
#include "Filas-Circulares.h"
int main(void)
{
	fila xFila;
	
	xFila.arrIntFila[0]=-1;
	xFila.arrIntFila[1]=-1;
	xFila.arrIntFila[2]=-1;
	xFila.arrIntFila[3]=-1;
	xFila.arrIntFila[4]=-1;
	
	SbInicializaFila(&xFila);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos el elemento 10");
	SbFilaCircularInsertar(&xFila, 10);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos el elemento 13");
	SbFilaCircularInsertar(&xFila,13);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Vamos a agregar 5 elementos mas");
	SbFilaCircularInsertar(&xFila, 15);
	SbFilaCircularInsertar(&xFila, 25);
	SbFilaCircularInsertar(&xFila, 35);
	SbFilaCircularInsertar(&xFila, 45);
	SbFilaCircularInsertar(&xFila, 55);
	
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos 2 elementos mas");
	SbFilaCircularInsertar(&xFila,78);
	SbFilaCircularInsertar(&xFila,89);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos dos elementos mas en la fila");
	SbFilaCircularInsertar(&xFila, 89);
	SbFilaCircularInsertar(&xFila, 59);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Eliminamos un elemento de la fila %d\n", FnIntFilaCircularEliminar(&xFila));
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	
	puts("Agregamos el elemento 96");
	SbFilaCircularInsertar(&xFila, 96);
	printf("Elementos en la fila %d\n", FnIntFilaCircularElementos(&xFila));
	printf("El frente de la fila: %d en pos %d\n", FnIntFilaFrente(&xFila), xFila.iFilaFrente);
	printf("El final de la fila es %d en pos %d\n", FnIntFilaFinal(&xFila), xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaVacia(&xFila) ? "TRUE" : "FALSE" );
	printf("La fila esta llena: %s\n\n", FnIntFilaCircularLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaCircularDespliegaVector(&xFila);
	return 0;
}
