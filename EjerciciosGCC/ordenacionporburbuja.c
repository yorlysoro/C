#include <stdio.h>
#define LIM 15

int main(void)
{
	int i = 0, j = 0, tamanyo, aux;
	int lista[LIM];
	
	printf("Longitud del vectos a ordenar ");
	scanf("%d", &tamanyo);
	if(tamanyo > LIM)
	{
		printf("El limite del vector se ha excedido");
		printf(", por favor cambie el limite en el codigo\n");
	}
	while(i<tamanyo)
	{
		i++;
		printf("Numero %d: ", i);
		scanf("%d", &lista[i-1]);
	}
	
	printf("\nEl vector introducido es el siguiente: \n");
	for(i=0; i<tamanyo; i++) printf("%d ", lista[i]);
	for(i=0; i<tamanyo-1; i++)
	{
		for(j=i+1; j<tamanyo; j++)
		{
			if(lista[i] > lista[j])
			{
				aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
	printf("\nEl vector ordenado es el siguiente: \n");
	for(i=0;i<tamanyo;i++) printf("%d ", lista[i]);
	printf("\n");
	return 0;
}
