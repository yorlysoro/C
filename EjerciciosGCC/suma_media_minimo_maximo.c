#include<stdio.h>
#define MIN(a,b) ((a < b) ? a : b)
#define MAX(a,b) ((a > b) ? a : b)

int main(void)
{
	int valores[] = {10,1,3,4,15,6,7,8,9,10};
	int i, tam, suma=0, minimo= valores[0], maximo=valores[0];
	float media;
	tam = sizeof(valores)/sizeof(int);
	for(i=0; i<tam;++i)
	{
		printf(" %d ", valores[i]);
		minimo=MIN(minimo, valores[i]);
		maximo=MAX(maximo, valores[i]);
		suma+=valores[i];
	}
	
	media=(float)suma/tam;
	printf("\nSuma = %d; Media = %f\nMinimo = %d; Maximo = %d\n", suma, media, minimo, maximo);
	return 0;
}
