#include <stdio.h>

void intercambiarValor(int v1, int v2);
void IntercambiarReferencia(int *pv1, int *pv2);

int main (void)
{
	int val1 = 10, val2 = 20;
	printf("Valores Iniciales: \n\tval1= %d; val2 = %d\n", val1, val2);
	
	intercambiarValor(val1, val2);
	printf("\nPaso de parametros por valor\n\tval1 = %d; val2 = %d\n",val1, val2);
	
	IntercambiarReferencia(&val1, &val2);
	printf("\nPaso de parametros por referencia:\n\tval1 = %d; val2 = %d\n", val1, val2);
	
	return 0;
}

void intercambiarValor(int v1, int v2)
{
	int tmp;
	tmp = v1;
	v1 = v2;
	v2 = tmp;
}

void IntercambiarReferencia(int *pv1, int *pv2)
{
	int tmp;
	tmp = *pv1;
	*pv1 = *pv2;
	*pv2 = tmp;
}
