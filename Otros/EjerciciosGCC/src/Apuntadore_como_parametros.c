/*
 * Apuntadore_como_parametros.c
 *
 *  Created on: 04/11/2016
 *      Author: yorlys
 */

#include <stdlib.h>
#include <stdio.h>

void SbTest0(int xDato)
{
	printf("EL valor de xDatos: %d\n", xDato);
	xDato++;
	printf("El valor de xDato: %d\n", xDato);
}

void SbTest1(int *pInteger)
{
	printf("El valor de la direccion del apuntador es %p\n", pInteger);
	printf("El valor que contiene la direccion del apuntador es %d\n", *pInteger);

	*pInteger = 20;

	printf("El valor modificado que contiene la direccion del apuntador es: %d\n\n",*pInteger);
}

void SbTest2(int **pInteger)
{
	int xInteger = 50;

	printf("Valor - direccion de pInteger %p\n", pInteger);
	printf("Valor - direccion de *pInteger %p\n", *pInteger);
	printf("Valor			  de **pInteger %d\n\n", **pInteger);

	*pInteger = &xInteger;

	printf("Valor - direccion de pInteger %p\n", pInteger);
	printf("Valor - direccion de *pInteger %p\n", *pInteger);
	printf("Valor			  de **pInteger %d\n\n", **pInteger);

}

int main(void)
{
	 int xEntero=10;
	 int *pEntero=&xEntero;

	 SbTest0(xEntero);
	 printf("El valor de xEntero:%d\n", xEntero);
	 printf("Direccion de xEntero:%p\n", &xEntero);


	printf("Valor - direccion de pEntero %p\n", pEntero);
	printf("Valor de direccion de pEntero %d\n", *pEntero);
	printf("Direccion			  de pEntero %p\n\n", &pEntero);

	SbTest1(&xEntero);

	printf("Valor de xEntero %d\n", xEntero);
	printf("Direccion de xEntero %p\n\n", &xEntero);

	printf("Valor - direccion de pEntero %p\n", pEntero);
	printf("Valor de direccion de pEntero %d\n", *pEntero);
	printf("Direccion			  de pEntero %p\n\n", &pEntero);

	xEntero = 30;

	SbTest1(pEntero);

	printf("Valor de xEntero %d\n", xEntero);
	printf("Direccion de xEntero %p\n\n", &xEntero);

	printf("Valor - direccion de pEntero %p\n", pEntero);
	printf("Valor de direccion de pEntero %d\n", *pEntero);
	printf("Direccion			  de pEntero %p\n\n", &pEntero);

	xEntero = 10;

	SbTest2(&pEntero);

	printf("Valor - direccion de pEntero %p\n", pEntero);
	printf("Valor de direccion de pEntero %d\n", *pEntero);
	printf("Direccion			  de pEntero %p\n\n", &pEntero);

	return 0;

}
