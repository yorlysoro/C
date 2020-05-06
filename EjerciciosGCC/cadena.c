#include <stdio.h>
int const max = 100;

void cuenta (char a[max]);

int main(void)
{
	char a[max];
	printf("Ingrese una cadena: ");
	gets(a);
	cuenta(a);
	return 0;
}

void cuenta(char a[max])
{
	int cont=0;
	while(*a++)
	{
		cont++;
	}
	printf("La longitud de la cadena es de %d caracteres\n", cont);
}
