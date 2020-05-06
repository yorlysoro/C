#include <stdio.h>

int main(void)
{
	int nota = 0;
	puts("Intrduzca la nota: ");
	scanf("%d", &nota);
	if(nota > 100)
	puts("nota alta");
	else if(nota < 100)
	puts("Nota baja");
	
	return 0;
}
