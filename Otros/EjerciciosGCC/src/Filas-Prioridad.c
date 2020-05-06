/*
 * Filas-Prioridad.c
 *
 *  Created on: 03/11/2016
 *      Author: yorlys
 */
#include "../headers/Filas-Prioridad.h"

int main(void)
{
	filaPrioridad xFila;
	elemento xElemento;

	strcpy(xFila.arrIntFila[0].cElemento, "NULO");
	xFila.arrIntFila[0].cPrioridad=-1;
	strcpy(xFila.arrIntFila[1].cElemento, "NULO");
	xFila.arrIntFila[1].cPrioridad=-1;
	strcpy(xFila.arrIntFila[2].cElemento, "NULO");
	xFila.arrIntFila[2].cPrioridad=-1;
	strcpy(xFila.arrIntFila[3].cElemento, "NULO");
	xFila.arrIntFila[3].cPrioridad=-1;
	strcpy(xFila.arrIntFila[4].cElemento, "NULO");
	xFila.arrIntFila[4].cPrioridad=-1;

	SbFilaPrioridadInicializa(&xFila);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"Doc1.doc");
	xElemento.cPrioridad = 0;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"Imag.bmp");
	xElemento.cPrioridad = 1;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"Datos.dat");
	xElemento.cPrioridad = 2;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"Calf.dat");
	xElemento.cPrioridad = 3;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"Boleta.dat");
	xElemento.cPrioridad = 1;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	xElemento = FnElemFilaPrioridadEliminar(&xFila);
	printf("Se elimino el elemento %s con Prioridad %d\n", xElemento.cElemento, xElemento.cPrioridad);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"List.dat");
	xElemento.cPrioridad = 0;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	xElemento = FnElemFilaPrioridadEliminar(&xFila);
	printf("Se elimino el elemento %s con Prioridad %d\n", xElemento.cElemento, xElemento.cPrioridad);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"List.txt");
	xElemento.cPrioridad = -2;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	strcpy(xElemento.cElemento,"List.jpg");
	xElemento.cPrioridad = 0;
	SbFilaPrioridadInsertar(&xFila,xElemento);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);

	xElemento = FnElemFilaPrioridadEliminar(&xFila);
	printf("Se elimino el elemento %s con Prioridad %d\n", xElemento.cElemento, xElemento.cPrioridad);

	xElemento = FnElemFilaPrioridadEliminar(&xFila);
	printf("Se elimino el elemento %s con Prioridad %d\n", xElemento.cElemento, xElemento.cPrioridad);

	printf("Elementos en la fila: %d\n", FnIntFilaPrioridadElementos(&xFila));

	xElemento = FnElemFilaPrioridadFrente(&xFila);
	printf("El frente de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFrente);
	xElemento = FnElemFilaPrioridadFinal(&xFila);
	printf("El final de la fila: Elemento:%s Prioridad:%d en pos:%d\n", xElemento.cElemento, xElemento.cPrioridad, xFila.iFilaFinal);
	printf("La fila esta vacia: %s\n", FnIntFilaPrioridadVacia(&xFila) ? "TRUE" : "FALSE");
	printf("La fila esta llena: %s\n", FnIntFilaPrioridadLlena(&xFila) ? "TRUE" : "FALSE");
	SbFilaPrioridadDespliegaVector(&xFila);


	return 0;
}
