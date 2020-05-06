#include <stdio.h>

int main(void)
{
	int x[100];
	int cont;
	
	for(cont=0;cont < 100;cont++)
	x[cont]= cont;
	
	printf("%d\n", x[4]);
	return 0;
}
