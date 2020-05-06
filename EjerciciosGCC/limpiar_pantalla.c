#include <stdio.h>
void LimpiarPantalla(int n);

int main(void)
{
	int numlin = 30;
	LimpiarPantalla(numlin);
	return 0;
}

void LimpiarPantalla(int n)
{
	while(n-- > 0)
	putchar('\n');
}
