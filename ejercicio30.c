#include <stdio.h>
#define sec_por_min 60
int main(void)
{
	int mint = 0, sec = 0, sec2 = 0;
	
	puts("Introduzca el numero de segundos que quiera convertir:");
	scanf("%i", &sec);
	
	mint = sec / sec_por_min;
	sec2 = sec % sec_por_min;
	
	printf("%d son %d minutos y %d segundos\n", sec, mint, sec2);
	
	return 0;
	
}
