#include<stdio.h>
#define ANCHO 66
#define FILAS 3

void linea();
void lados();

int main(void)
{
	printf("\n\n\n\n");
	linea();
	lados();
	printf("	*\t\t\t\t Bienvenido a C \t\t\t\t*\n");
	lados();
	linea();
	printf("\n\n\n\n");
	return 0;
}

void linea()
{
	int x;
	printf("     ");
	for(x=0; x <= ANCHO; ++x) putchar('*');
	putchar('\n');
}

void lados()
{
	int y;
	for(y = 0; y<=FILAS; ++y) 
	printf("		*\t\t\t\t\t\t\t\t\t\t\t*\n");
}
