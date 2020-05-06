#include <stdio.h>

void dias(int n);
int main(void)
{
	int num;
	
	printf("Introducir n de Dia: ");
	scanf("%i", &num);
	
	dias(num);
	return 0;
}

void dias(int n)
{
	char *dia[] = { "N de dia no valido",
		"lunes", "Martes","Miercoles", "jueves", "Viernes", "Sabado", "Domingo"};
	printf("%s\n", dia[n]);
}
