#include "filas.h"

int FnIntFilaElementosII(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
		return 0;
	else
		return pFila->iFilaFinal-pFila->iFilaFrente+1;
}

int FnIntFilaLlenaII(fila *pFila)
{
	if(FnIntFilaElementosII(pFila)==FILA_TAMANIO)
		return TRUE;
	else
		return FALSE;
}

void SbFilaInsertarII(fila *pFila, int iElemento)
{
	if(FnIntFilaLlenaII(pFila))
		printf("La fila esta llena no se puede agregar el elemento %d\n", iElemento);
	else
	{
		if(pFila->iFilaFinal==-1)
			pFila->iFilaFrente=0;
		else
			if(pFila->iFilaFinal+1==FILA_TAMANIO)
			SbFilaRecorreII(pFila);
		pFila->arrIntFila[++pFila->iFilaFinal]=iElemento;
	}
}

void SbFilaRecorreII(fila *pFila)
{

	int iIndice1;
	int iIndice2;
	
	for(iIndice1 = 0, iIndice2=pFila->iFilaFrente; iIndice2<=pFila->iFilaFinal; iIndice1++, iIndice2++)
		pFila->arrIntFila[iIndice1] = pFila->arrIntFila[iIndice2];
	
	pFila->iFilaFinal = pFila->iFilaFinal - pFila->iFilaFrente;
	
	pFila->iFilaFrente=0;
}

int FnIntFilaEliminarII(fila *pFila)
{
	int iResult;
	if(FnIntFilaVacia(pFila))
	{
		printf("La fila esta vacia no es posible sacar elementos\n");
		iResult=-1;
	}
	else
	{
		iResult = pFila->arrIntFila[pFila->iFilaFrente];
		
		if(pFila->iFilaFinal==pFila->iFilaFrente)
		{
			pFila->iFilaFinal=-1;
			pFila->iFilaFrente=-1;
		}
		else
			pFila->iFilaFrente++;
	}
	return(iResult);
		
		
}
