#include <stdio.h>
#define N 3

int main(void)
{
	struct agenda 
	{
		char nombre[25];
		char telefono[10];
		int edad;
	};
	struct agenda amigos[N] = {{"Pepe", "913472314",18}, {"Juan", "915547623", 19},
		{"Rosa", "917456778",21}};
	int i;
	for (i = 0; i<N; ++i)
	{
		printf("\nAmigo %s\t telefono %s\t edad %d", amigos[i].nombre, amigos[i].telefono, amigos[i].edad);
	}
	printf("\n");
	return 0;
}
