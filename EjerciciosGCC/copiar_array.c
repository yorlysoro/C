#include <stdio.h>
/*Intercambia los arrays uno en dos y luego lo imprimer*/
void copiarArray(int a[], int b[], int tamanio);
void escribirArray(int a[], int tamanio);

int main(void)
{
	int uno[] = {2,4,5,6,7,8,9,11};
	int dos[8];
	printf("Array uno:\n");
	escribirArray(uno,8);
	copiarArray(uno,dos,8);
	printf("Array dos:\n");
	escribirArray(dos,8);
	return 0;
}

void escribirArray(int a[], int tamanio)
{
	int i;
	for(i = 0;  i < tamanio; i++)
	printf("%d", a[i]);
	putchar('\n');
}

void copiarArray(int a[], int b[], int tamanio)
{
	int i;
	for(i = 0; i < tamanio; i++)
	{
		b[i] = a[i];
	}
}
