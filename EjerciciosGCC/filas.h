#define TRUE 1
#define FALSE 0
#define FILA_TAMANIO 5

typedef struct stcFila
{
	int iFilaFrente;
	int iFilaFinal;
	
	int arrIntFila[FILA_TAMANIO];
}fila;

void SbInicializaFila(fila *pFila)
{
	puts("Pila inicializada");
	
	pFila->iFilaFrente = -1;
	pFila->iFilaFinal = -1;
}


int FnIntFilaElementos(fila *pFila)
{
	return pFila->iFilaFinal+1;
}

int FnIntFilaVacia(fila *pFila)
{
	if(pFila->iFilaFinal==-1)
		return TRUE;
	else
		return FALSE;
}

int FnIntFilaLlena(fila *pFila)
{
	if(pFila->iFilaFinal+1 == FILA_TAMANIO)
		return TRUE;
	else
		return FALSE;
}

int FnIntFilaFrente(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
		return(-1);
	else
	return pFila->arrIntFila[pFila->iFilaFrente];
}

int FnIntFilaFinal(fila *pFila)
{
	if(FnIntFilaVacia(pFila))
		return(-1);
	else
		return pFila->arrIntFila[pFila->iFilaFinal];
}

void SbFilaInsertar(fila *pFila, int iElemento)
{
	if(FnIntFilaLlena(pFila))
		printf("La pila esta llena, no se pudo agregar el elemento %d\n", iElemento);
	else
	{
		if(pFila->iFilaFinal == -1)
			pFila->iFilaFrente = 0;
		
		pFila->arrIntFila[++pFila->iFilaFinal] = iElemento;
	}
}

int FnIntFilaEliminar(fila *pFila)
{
	int iResult;
	
	if(FnIntFilaVacia(pFila))
	{
		printf("La fila esta vacia no se pueden sacar mas elementos\n");
		iResult = pFila->arrIntFila[pFila->iFilaFinal];
	}
	else
	{
		iResult = pFila->arrIntFila[pFila->iFilaFrente];
		if(pFila->iFilaFinal==0)
		{
			pFila->iFilaFinal=-1;
			pFila->iFilaFrente=-1;
		}
		else
			SbFilaRecorre(pFila);
	}
	return (iResult);
		
}

void SbFilaRecorre(fila *pFila)
{
	int iIndice;
	
	for(iIndice=1;iIndice<=pFila->iFilaFinal; iIndice++)
		pFila->arrIntFila[iIndice-1] = pFila->arrIntFila[iIndice];
		
	pFila->iFilaFinal--;
}
