#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t inicio, final;
	double tiempo, cont;
	inicio = time(NULL);
	for(cont = 0; cont < 50000; cont++)
	final = time(NULL);
	tiempo = difftime(final, inicio);
	printf("Tiempo: %.1f", tiempo);
	return 0;
}

