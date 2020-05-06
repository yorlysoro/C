/*
 * Filas-Prioridad.h
 *
 *  Created on: 03/11/2016
 *      Author: yorlys
 */

#ifndef HEADERS_FILAS_PRIORIDAD_H_
#define HEADERS_FILAS_PRIORIDAD_H_
#define FILA_TAMANIO 5
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <string.h>

typedef struct stcElemento
{
	char cElemento[10];
	char cPrioridad;
}elemento;

typedef struct stcFilaPrioridad
{
	int iFilaFrente;
	int iFilaFinal;

	elemento arrIntFila[FILA_TAMANIO];
}filaPrioridad;

void SbFilaPrioridadInicializa(filaPrioridad *pFila)
{
	pFila->iFilaFrente=-1;
	pFila->iFilaFinal=-1;

	puts("Fila Inicializada\n");
}

int FnIntFilaPrioridadVacia(filaPrioridad *pFila)
{
	if(pFila->iFilaFinal==-1)
		return TRUE;
	else
		return FALSE;
}

elemento FnElemFilaPrioridadFrente(filaPrioridad *pFila)
{
	elemento xElemento;
	strcpy(xElemento.cElemento, "Nulo");
	xElemento.cPrioridad = -1;

	if(FnIntFilaPrioridadVacia(pFila))
		return (xElemento);
	else
		return (pFila->arrIntFila[pFila->iFilaFrente]);
}


elemento FnElemFilaPrioridadFinal(filaPrioridad *pFila)
{
	elemento xElemento;
	strcpy(xElemento.cElemento, "Nulo");
	xElemento.cPrioridad = -1;

	if(FnIntFilaPrioridadVacia(pFila))
		return (xElemento);
	else
		return (pFila->arrIntFila[pFila->iFilaFinal]);
}

int FnIntFilaPrioridadElementos(filaPrioridad *pFila)
{
	if(FnIntFilaPrioridadVacia(pFila))
		return 0;
	else
		if(pFila->iFilaFinal >= pFila->iFilaFrente)
			return pFila->iFilaFinal - pFila->iFilaFrente + 1;
		else
			return FILA_TAMANIO - pFila->iFilaFrente + pFila->iFilaFinal + 1;

}

int FnIntFilaPrioridadLlena(filaPrioridad *pFila)
{
	if(FnIntFilaPrioridadElementos(pFila)==FILA_TAMANIO)
		return TRUE;
	else
		return FALSE;
}

void SbFilaPrioridadInsertar(filaPrioridad *pFila, elemento pElemento)
{
	elemento xElementoFinal;

	char cIndice,cIndice2;

	xElementoFinal = FnElemFilaPrioridadFinal(pFila);

	if(FnIntFilaPrioridadLlena(pFila))
		printf("La fila esta llena ya no es posible cargar el elemento %s\n", pElemento);
	else
	{
		if(pFila->iFilaFinal==-1)
		{
			pFila->iFilaFrente=0;
			pFila->arrIntFila[++pFila->iFilaFinal]=pElemento;
		}
		else
			if(xElementoFinal.cPrioridad >= pElemento.cPrioridad)
				if(pFila->iFilaFinal +1 == FILA_TAMANIO)
				{
					pFila->iFilaFinal=0;
					pFila->arrIntFila[pFila->iFilaFinal]=pElemento;
				}
				else
					pFila->arrIntFila[++pFila->iFilaFinal]=pElemento;
			else
			{
				if(pFila->iFilaFinal >= pFila->iFilaFrente)
				{
					for(cIndice=pFila->iFilaFrente; cIndice<=pFila->iFilaFinal;cIndice++)
						if(pElemento.cPrioridad > pFila->arrIntFila[cIndice].cPrioridad)
							break;
					if(pFila->iFilaFinal+1==FILA_TAMANIO)
						pFila->arrIntFila[0] = pFila->arrIntFila[pFila->iFilaFinal];
					else
						pFila->arrIntFila[pFila->iFilaFinal+1]=pFila->arrIntFila[pFila->iFilaFinal];

					for(cIndice2=pFila->iFilaFinal-1; cIndice2>=cIndice; cIndice2--)
						pFila->arrIntFila[cIndice2+1]=pFila->arrIntFila[cIndice2];

					pFila->arrIntFila[cIndice]=pElemento;

					if(pFila->iFilaFinal+1 == FILA_TAMANIO)
						pFila->iFilaFinal=0;
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
							pFila->arrIntFila[cIndice2+1]=pFila->arrIntFila[cIndice2];

						pFila->arrIntFila[0]=pFila->arrIntFila[pFila->iFilaFinal];

						for(cIndice2= pFila->iFilaFinal-1;cIndice2>=cIndice;cIndice2--)
							pFila->arrIntFila[cIndice2+1]=pFila->arrIntFila[cIndice2];

						pFila->arrIntFila[cIndice] = pElemento;

						pFila->iFilaFinal++;
					}
					else
					{
						for(cIndice=0;cIndice<=pFila->iFilaFinal;cIndice++)
							if(pElemento.cPrioridad > pFila->arrIntFila[cIndice].cPrioridad)
								break;

						for(cIndice2=pFila->iFilaFinal;cIndice2>=cIndice;cIndice2--)
							pFila->arrIntFila[cIndice2+1]=pFila->arrIntFila[cIndice2];

						pFila->arrIntFila[cIndice]=pElemento;
						for(cIndice2= pFila->iFilaFinal-1;cIndice2>=cIndice;cIndice2--)
					pFila->iFilaFinal++;
					}
				}
			}
	}
}

elemento FnElemFilaPrioridadEliminar(filaPrioridad *pFila)
{
	elemento eResult;

	if(FnIntFilaPrioridadVacia(pFila))
	{
		printf("La fila esta vacia no es posible sacar elementos\n");
		strcpy(eResult.cElemento, "Nulo");
		eResult.cPrioridad=-1;
	}
	else
	{
		eResult=pFila->arrIntFila[pFila->iFilaFrente];
		strcpy(pFila->arrIntFila[pFila->iFilaFrente].cElemento, "Nulo");
		pFila->arrIntFila[pFila->iFilaFrente].cPrioridad=-1;
		if(pFila->iFilaFinal == pFila->iFilaFrente)
		{
			pFila->iFilaFinal=-1;
			pFila->iFilaFrente=-1;
		}
		else
			if(pFila->iFilaFrente+1==FILA_TAMANIO)
				pFila->iFilaFrente=0;
			else
				pFila->iFilaFrente++;
	}
	return (eResult);
}

void SbFilaPrioridadDespliegaVector(filaPrioridad *pFila)
{
	int iIndice;

	printf("Fila->| ");
	for(iIndice=0;iIndice<FILA_TAMANIO;iIndice++)
		printf("%s[%d] | ", pFila->arrIntFila[iIndice].cElemento, pFila->arrIntFila[iIndice].cPrioridad);
	printf("\n\n");
}
#endif /* HEADERS_FILAS_PRIORIDAD_H_ */
