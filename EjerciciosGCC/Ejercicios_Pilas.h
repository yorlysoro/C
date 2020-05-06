#define ESPACIO_EN_BLANCO 32
#define TRUE 1
#define FALSE 0
#define PILA_TAMANIO 50
typedef struct strPilas{
	int iPilaTope;
	int arrIntPila[PILA_TAMANIO];
}pila;

void SbPilaInicializa(pila *pPila)
{
	pPila->iPilaTope=-1;
}


int FnIntPilaVacia(pila *pPila)
{
	if(pPila->iPilaTope==-1)
	return TRUE;
	else
	return FALSE;
}

int FnIntPilaLLena(pila *pPila)
{
	if(pPila->iPilaTope==PILA_TAMANIO-1)
	return TRUE;
	else
	return FALSE;
}

int FnIntPilaELementos(pila *pPila)
{
	return pPila->iPilaTope+1;
}

//void SbPilaCima(pila *pPila)
//{
	//if(FnIntPilaVacia(pPila))
	//printf("La pila esta vacia; no ha elemento en la cima\n");
	//else
	//printf("Pila Cima: %d", pPila->arrIntPila[pPila->iPilaTope]);
//}

int FnIntPilaCima(pila *pPila)
{
	if(FnIntPilaVacia(pPila))
	{
	puts("La pila esta vacia; no hay elementos en la cima");
	return -1;
	}
	else
	return pPila->arrIntPila[pPila->iPilaTope];
}
void SbPilaPush(pila *pPila, int iElemento)
{
	if(FnIntPilaLLena(pPila))
	printf("La pila esta llena y no es posible agregar el elemento: %d\n", iElemento);
	else
	{
		pPila->iPilaTope++;
		pPila->arrIntPila[pPila->iPilaTope] = iElemento;
	}
}

int FnIntPilaPop(pila *pPila)
{
	if(FnIntPilaVacia(pPila))
	{
		return pPila->iPilaTope;
	}
	else
	{
		return(pPila->arrIntPila[pPila->iPilaTope--]);
	}
}
