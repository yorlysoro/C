/*
 * Fila_prioridad.c
 * 
 * Copyright 2016 copyleft <copyleft@debian>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#define FILA_TAMANIO 5
#define TRUE 1
#define FALSE 0
#include <string.h>

typedef struct stcElemento{
	char cElemento[10];
	char cPrioridad;
}elemento;

typedef struct stcFilaPrioridad{
	int iFilaFinal;
	int iFilaFrente;
	elemento arrIntFila[FILA_TAMANIO];
}filapriorida;

void SbFilaPrioridadInicializa(filapriorida *pFila)
{
	pFila->iFilaFinal = -1;
	pFila->iFilaFrente = -1;
	puts("Fila inicializada");
}

int FnIntFilaPrioridadVacia(filapriorida *pFila)
{
	if(pFila->iFilaFinal == -1)
		return TRUE;
	else
		return FALSE;
}

elemento FnElemFilaPrioridadFrente(filapriorida *pFila)
{
	elemento xElemento;
	strcpy(xElemento.cElemento, "Nulo");
	xElemento.cPrioridad = -1;
	
	if(FnIntFilaPrioridadVacia(pFila))
		return (xElemento);
	else
		return (pFila->arrIntFila[pFila->iFilaFrente]);
}

elemento FnElemFilaPrioridadFinal(filapriorida *pFila)
{
	elemento xElemento;
	strcpy(xElemento.cElemento, "Nulo");
	xElemento.cPrioridad = -1;
	
	if(FnIntFilaPrioridadVacia(pFila))
		return (xElemento);
	else
		return(pFila->arrIntFila[pFila->iFilaFinal]);
}
int FnIntFilaPrioridadElementos(filapriorida *pFila)
{
	if(FnIntFilaPrioridadVacia(pFila))
		return 0;
	else
		if(pFila->iFilaFinal >= pFila->iFilaFrente)
			return pFila->iFilaFinal - pFila->iFilaFrente + 1;
		else
			return FILA_TAMANIO - pFila->iFilaFrente + pFila->iFilaFinal + 1;
}

int FnIntFilaPrioridadLlena(filapriorida *pFila)
{
	if(FnIntFilaPrioridadElementos(pFila) == FILA_TAMANIO)
		return TRUE;
	else
		return FALSE;
}

void SbFilaPrioridadInsertar(filapriorida *pFila, elemento pElemento)
{
	elemento xElementoFinal;
	int cIndice,cIndice2;
	
	xElementoFinal = FnElemFilaPrioridadFinal(pFila);
	
	if(FnIntFilaPrioridadLlena(pFila))
		printf("La fila esta llena no puede cargar el elemento %s\n", pElemento);
	else
	{
		if(pFila->iFilaFinal == -1)
		{
			pFila->iFilaFrente = 0;
			pFila->arrIntFila[++pFila->iFilaFinal] = pElemento;
		}
		else
			if(xElementoFinal.cPrioridad >= pElemento.cPrioridad)
				if(pFila->iFilaFinal + 1 == FILA_TAMANIO)
				{
					pFila->iFilaFinal = 0;
					pFila->arrIntFila[pFila->iFilaFinal] = pElemento;
				}
				else
					pFila->arrIntFila[++pFila->iFilaFinal] = pElemento;
			else
			{
				if(pFila->iFilaFinal >= pFila->iFilaFrente)
				{
					for(cIndice=pFila->iFilaFrente; cIndice <= pFila->iFilaFinal; cIndice++)
						if(pElemento.cPrioridad > pFila->arrIntFila[cIndice].cPrioridad)
							break;
					if(pFila->iFilaFinal + 1 == FILA_TAMANIO)
						pFila->arrIntFila[0] = pFila->arrIntFila[pFila->iFilaFinal];
					else
						pFila->arrIntFila[pFila->iFilaFinal+1] = pFila->arrIntFila[pFila->iFilaFinal];
					for(cIndice2 = pFila->iFilaFinal-1; cIndice2>=cIndice; cIndice2--)
						pFila->arrIntFila[cIndice2+1] = pFila->arrIntFila[cIndice2];
						
					pFila->arrIntFila[cIndice] = pElemento;
					
					if(pFila->iFilaFinal + 1 == FILA_TAMANIO)
						pFila->iFilaFinal = 0;
					else
						pFila->iFilaFinal++;
				}
				else
				{
					for(cIndice=pFila->iFilaFrente;cIndice<=FILA_TAMANIO-1;cIndice++)
						if(pElemento.cPrioridad > pFila->arrIntFila[cIndice].cPrioridad)
							break;
					if(cIndice<FILA_TAMANIO)
					{
						for(cIndice2=pFila->iFilaFinal;cIndice2==0;cIndice2--)
							pFila->arrIntFila[cIndice2+1] = pFila->arrIntFila[cIndice2];
						pFila->arrIntFila[0] = pFila->arrIntFila[pFila->iFilaFinal];
						for(cIndice2 = pFila->iFilaFinal-1;cIndice2>=cIndice;cIndice2--)
							pFila->arrIntFila[cIndice2+1] = pFila->arrIntFila[cIndice2];
						pFila->arrIntFila[cIndice] = pElemento;
						pFila->iFilaFinal++;
					}
					else
					{
						for(cIndice=0;cIndice<=pFila->iFilaFinal;cIndice++)
							if(pElemento.cPrioridad > pFila->arrIntFila[cIndice].cPrioridad)
								break;
						for(cIndice2 = pFila->iFilaFinal;cIndice2>=cIndice;cIndice2--)
							pFila->arrIntFila[cIndice2+1] = pFila->arrIntFila[cIndice2];
							
						pFila->arrIntFila[cIndice] = pElemento;
						
						for(cIndice2=pFila->iFilaFinal-1;cIndice2>=cIndice;cIndice--);
						pFila->iFilaFinal++;
					}
				}
			}
	}
}

elemento FnElemFilaPrioridadEliminar(filapriorida *pFila)
{
	elemento eResult;
	
	if(FnIntFilaPrioridadVacia(pFila))
	{
		printf("La fila esta vacia no es posibles sacar elementos\n");
		strcpy(eResult.cElemento, "NULO");
		eResult.cPrioridad = -1;
	}
	else
	{
		eResult = pFila->arrIntFila[pFila->iFilaFrente];
		strcpy(pFila->arrIntFila[pFila->iFilaFrente].cElemento,"NULO");
		pFila->arrIntFila[pFila->iFilaFrente].cPrioridad=-1;
		if(pFila->iFilaFinal == pFila->iFilaFrente)
		{
			pFila->iFilaFinal = -1;
			pFila->iFilaFrente = -1;
		}
		else
			if(pFila->iFilaFrente+1 == FILA_TAMANIO)
				pFila->iFilaFrente = 0;
			else
				pFila->iFilaFrente++;
	}
	return (eResult);
}

void SbFilaPrioridadDespliegaVector(filapriorida *pFila)
{
	int iIndice;
	printf("Fila->| ");
	for(iIndice=0;iIndice<FILA_TAMANIO;iIndice++)
		printf("%s[%d] | ", pFila->arrIntFila[iIndice].cElemento, pFila->arrIntFila[iIndice].cPrioridad);
	putchar('\n');
}
int main(int argc, char **argv)
{
	filapriorida xFila;
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
	return 0;
}

