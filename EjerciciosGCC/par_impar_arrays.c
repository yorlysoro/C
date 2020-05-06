#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100

void escribirArray(int a[], int tamanio);

int main(void)
{
	int a[TAM];
	int par[TAM]={0};
	int impar[TAM]={0};
	int i,j;
	
	srand(time(NULL));
	
	for( i=0 ; i<TAM ; i++ )
	{
		a[i]=rand()%100+1;
	}
	
	printf("Primer Array:\n");
	escribirArray(a,TAM);
	
	for(i = 0; i<TAM; i++)
	{
		if(a[i]%2 == 0)
			par[i] = a[i];
		else
			impar[i] = a[i];
	}
	printf("\nPar:\n");
	escribirArray(par,TAM);
	printf("\nImpar:\n");
	escribirArray(impar,TAM);
	
	j = 0;
	
	for(i=0;i<TAM;i++)
	{
		if(par[i]!=0){
			a[j] = par[i];
			j++;
		}
	}
	
	for(i=0; i < TAM; i++)
	{
		if(impar[i] != 0){
		a[j] = impar[i];
		j++;
		}
	}
	printf("\nResultado final:\n");
	escribirArray(a,TAM);
	return 0;
}


void escribirArray(int a[], int tamanio)
{
	int i;
	for(i = 0; i < tamanio; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}
