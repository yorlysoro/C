#include "filas.h"

int FnIntFilaCircularElementos(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
		return 0;
	else
		if(pFila->iFilaFinal>=pFila->iFilaFrente)
			return (pFila->iFilaFinal - pFila->iFilaFrente +1);
		else
			return (FILA_TAMANIO - pFila->iFilaFrente + pFila->iFilaFinal +1);
}

int FnIntFilaCircularLlena(fila *pFila)
{
	if(FnIntFilaCircularElementos(pFila)==FILA_TAMANIO)
		return TRUE;
	else
		return FALSE;
}

void SbFilaCircularInsertar(fila *pFila, int iElemento)
{
	if(FnIntFilaCircularLlena(pFila))
		printf("La fila esta llena y no es posible agregar el elemento: %d\n", iElemento);
		
	else
	{
		if(pFila->iFilaFinal == -1)
		{
			pFila->iFilaFrente = 0;
			pFila->arrIntFila[++pFila->iFilaFinal] = iElemento;
		}
		else
			if(pFila->iFilaFinal + 1 == FILA_TAMANIO)
			{
				pFila->iFilaFinal = 0;
				pFila->arrIntFila[pFila->iFilaFinal] = iElemento;
			}
			else
				pFila->arrIntFila[++pFila->iFilaFinal] = iElemento;	
	}
}

int FnIntFilaCircularEliminar(fila *pFila)
{
	int iResult;
	
	if(FnIntFilaVacia(pFila))
	{
		printf("La fila esta vacia no es posible sacar elementos\n");
		iResult = -1;
	}
	else
	{
		iResult = pFila->arrIntFila[pFila->iFilaFrente];
		pFila->arrIntFila[pFila->iFilaFrente] = -1;
		
		if(pFila->iFilaFinal==pFila->iFilaFrente)
		{
			pFila->iFilaFinal = -1;
			pFila->iFilaFrente = -1;
		}
		else
			if(pFila->iFilaFrente+1==FILA_TAMANIO)
				pFila->iFilaFrente=0;
			else
				pFila->iFilaFrente++;
	}
	return (iResult);
}

void SbFilaCircularDespliegaVector(fila *pFila)
{
	int iIndice;
	
	printf("Fila->| ");
	for(iIndice=0; iIndice<FILA_TAMANIO;iIndice++)
		printf("%d | ", pFila->arrIntFila[iIndice]);
	printf("\n\n");
}
