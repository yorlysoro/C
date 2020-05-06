#include <stdio.h>
int main(void)
{
	float promedio, notas, notas_total;
	int n = 5;
	
	for(n = 1; n <= 5; n++)
	{
		printf("Calificacion del estudiante %d\n", n);
		scanf("%f", &notas);
		notas_total += notas;
	}
	promedio = notas_total/(n-1);
	printf("El promedio de las notas es: %.2f\n", promedio);
	return 0;
}
