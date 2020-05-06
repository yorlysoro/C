/*
 * Gestions_Dinamica_De_Memoria.c
 *
 *  Created on: 04/11/2016
 *      Author: yorlys
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Test
{
	char xChar;
	int xInt;
}test;

int main(void)
{
	int *pEntero;
	pEntero = (int *)malloc(sizeof(int));

	if(pEntero==NULL)
		printf("No puede reservar memoria\n");

	*pEntero = 90;

	printf("pEntero = %d\n", *pEntero);

	free(pEntero);

//	char *pCadena;
//
//	pCadena = (char *)malloc(14);
//
//	strcpy(pCadena, "jaorsoftware");
//
//	printf("pCadena = %s\n", *pCadena);
//
//	free(pCadena);

	test *xTest;
	xTest = (struct Test*)malloc(sizeof(xTest));
	xTest->xInt=10;
	xTest->xChar='A';

	printf("xInt = %d\n", xTest->xInt);
	printf("xChar = %c\n", xTest->xChar);

	free(xTest);

//	void *pVoid;
//	int iCuenta;
//	long lMemoria = 0;
//
//	for(iCuenta = 1; ; iCuenta++)
//	{
//		pVoid = malloc(1000);
//		if(pVoid == NULL)
//			break;
//		lMemoria += 1000;
//	}
//	printf("\nTotal de memoria Reservada %ul\n", lMemoria);
	return 0;
}
