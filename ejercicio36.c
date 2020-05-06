#include <stdio.h>

int main(void)
{
	int mes1 = 31, mes2 = 30, mes3 = 28, meses = 0;
	
	puts("Introduzca el numero de mes");
	scanf("%d", &meses);
	while(meses != 0)
	{
		if(meses == 1 || meses == 3 || meses == 5 || meses == 7 || meses == 8 || meses == 10 || meses == 12)
		printf("El mes %d tiene %d dias\n", meses, mes1);
		else if(meses == 4 || meses == 6 || meses == 9 || meses == 11)
		printf("El mese %d tiene %d dias\n", meses, mes2);
		else if(meses == 2)
		printf("El mes %d tiene %d dias\n", meses, mes3);
		else
		puts("Ese mes no existe");
	
		puts("Introduzca el numero de dias de un mes");
		scanf("%d", &meses);
	 }
	 return 0;
}
