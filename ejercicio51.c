#include <stdio.h>

int boolean(int n, int m);

int main(void)
{
	int n, m;
	int booleano = 0;
	
	puts("Introduzca dos numeros");
	scanf("%d %d", n, m);
	
	booleano = boolean(n,m);
	
	if(booleano == 1)
	puts("Es divisible true");
	else
	puts("No es divisible false");
	
	return 0;
}

int boolean(int n, int m)
{
	int r;
	
	r = n % m;
	
	if(r == 0)
	return 1;
	else
	return 0;
}
