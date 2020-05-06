#include <stdio.h>

int main(void)
{
	struct ficha{
		int balance;
		char nombre[80];
	}*p;
	
	printf("Nombre: ");
	gets(p->nombre);
	printf("\nBalance: ");
	scanf("%i", &p->balance);
	
	printf("%s\n", p->nombre);
	printf("%d\n", p->balance);
	return 0;
}
