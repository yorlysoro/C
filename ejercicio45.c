#include <stdio.h>
#define sec_por_min 60
#define sec_por_hora 3600
#define sec_por_dia  86400
#define sec_por_semana 604800

int main(void)
{
	float sem = 0;
	int dia = 0, hor = 0, min = 0, sec1 = 0, sec2 = 0;
	
	puts("Introduzca los segundos");
	scanf("%d", &sec2);
	
	sem = sec2 / sec_por_semana;
	dia = sec2 / sec_por_dia;
	hor = sec2 / sec_por_hora;
	min = sec2 % sec_por_min;
	sec1 = sec2 % sec_por_min;
	
	printf("%.2f Semanas %d dias %d horas %d minutos con %d segundos\n", sem, dia, hor, min, sec1);
	return 0;
}
