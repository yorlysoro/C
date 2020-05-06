#include <stdio.h>

char argumento(int n);
int main(void)
{
	int num = 0;
	char car[1];
	puts("Introduzca un numero");
	scanf("%d", &num);
	car[0] = argumento(num);
	if(car[0] == 'P')
	puts("P");
	else
	puts("N");	
	puts("Fin del programa");
	return 0;
}
char argumento(int n)
{
	char letra[1];
	if(n > 0)
	letra[0] = 'P';
	else if(n <= 0)
	letra[0] = 'N';
	return letra[0];
}
