#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000

void escribirArray(char a[], int tamanio);

int main(void)
{
	char letra[TAM];
	char AaZ[26];
	
	int i,j,cont;
	
	srand(time(NULL));
	
	for(i = 65; i <= 90; i++)
	{
		AaZ[i-65] = i;
	}
	
	for(i = 0; i < TAM; i++)
	{
		letra[i] = rand()%26+65;
	}
	printf("Array Inicial:\n");
	escribirArray(letra,TAM);
	for(i = 0; i<26; i++)
	{
		cont = 0;
		for(j= 0; j<TAM;j++)
		{
			if(AaZ[i] == letra[j]) cont++;
		}
		printf("La letra %c aparece %i veces\n", 65+i,cont);
	}
	return 0;
}

void escribirArray(char a[], int tamanio)
{
	int i;
	for(i = 0; i < tamanio; i++)
	{
		printf("%c ", a[i]);
	}
	putchar('\n');
}
