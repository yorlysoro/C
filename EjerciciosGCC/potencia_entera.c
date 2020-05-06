#include <stdio.h>

long poten_inter(int base, int expo);
long poten_recu(int base, int expo);

int main(void)
{
	long potencia;
	int b, e;
	printf("\nEscriba una base entera para la operaion b = ");
	scanf("%d", &b);
	printf("\nEscriba un exponente entero para la operacion e = ");
	scanf("%d", &e);
	
	potencia = poten_recu(b,e);
	printf("\nEl resultado de la potencia en forma recursiva = %ld\n", potencia);
	
	potencia = poten_inter(b,e);
	printf("\nEl resultado de la potencia en forma iteractiva = %ld\n", potencia);
	return 0;
}

long poten_inter(int base, int expo)
{
	long p = 1;
	int i;
	for(i=1; i<=expo;i++) p*=base;
	return(p);
}

long poten_recu(int base, int expo)
{
	long p;
	if(base == 0) return 0;
	if(expo == 0) return 1;
	
	p= base * poten_recu(base, expo-1);
	return (p);
}
