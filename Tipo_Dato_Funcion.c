#include <stdio.h>

typedef int (funcion)(int a, int b);

int suma_funciones(funcion, funcion, int, int);

int suma(int, int);
int multi(int, int);
void resultado(int, int);

int main(void)
{
	int a = 3, b = 3;
	resultado(a,b);
	return 0;
}

int suma(int a, int b)
{
	return a + b;
}

int multi(int a, int b)
{
	return a * b;
}

void resultado(int a, int b)
{
	int funcion_result = suma_funciones(suma, multi, a, b);
	printf("La suma es %d\n", funcion_result);
}

int suma_funciones(funcion f1, funcion f2, int a, int b)
{
	int resultado;
	
	resultado = f1(a,b) + f2(a,b);
	
	return resultado;
}
