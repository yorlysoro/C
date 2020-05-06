#include <stdio.h>
int vglobal = 100;

void suma1(int x);
void suma2(int x);

int main(void)
{
	extern int vglobal;
	int vlocal = 200;
	
	printf("\nLa variable vglobal en main vale = %d\n", vglobal);
	printf("\nLa variable vlocal en main vale = %d\n", vlocal);
	
	suma1(vlocal);
	
	printf("\nLa variable vglobal despeus de suma1 vale = %d\n", vglobal);
	printf("\nLa variable vlocal despues de suma1 vale = %d\n", vlocal);
	
	suma2(vlocal);
	printf("\nLa variable vglobal despues de suma2 vale = %d\n", vglobal);
	printf("\nLa variable vlocal despues de suma2 vale = %d\n", vlocal);
	
	return 0;
}

void suma1(int x)
{
	extern int vglobal;
	++x;
	++vglobal;
	printf("\nLa variable vglobal dentro de suma1 vale = %d\n", vglobal);
	printf("\nEl argumento(vlocal) dentro de suma1 vale = %d\n", x);
}


void suma2(int x)
{
	extern int vglobal;
	++x;
	++vglobal;
	printf("\nLa variable vglobal dentro de suma2 vale = %d\n", vglobal);
	printf("\nEl argumento (vlocal) dentro de suma2 vale = %d\n", x);
}
