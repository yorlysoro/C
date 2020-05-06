#include <stdio.h>
int main(void)
{
	double Coste, Depreciacion, Valor_Recuperacion, Valor_Actual, Acumulado, Valor_Anual;
	int Anio, Vida_Util;
	puts("Introduzca coste, valor de recuperacion y vida util ");
	scanf("%1f %1f %1f",  &Coste, &Valor_Recuperacion, &Vida_Util);
	puts("Introduzca año actual");
	scanf("%i", &Anio);
	Valor_Actual = Coste;
	Depreciacion = (Coste-Valor_Recuperacion)/Vida_Util;
	Acumulado = 0;
	puts("Año Depreciacion Dep. Acumulada");
	while(Anio < Vida_Util)
	{
		Acumulado = Acumulado + Depreciacion;
		Valor_Actual = Valor_Actual - Depreciacion;
		printf("Año: %d, Depreciacion: %.21f, %.21f Acumulada", Anio, Depreciacion, Acumulado);
		Anio = Anio + 1;
	}
	return 0;
}
