#include <stdio.h>

int main(void)
{
	int fahrenheit, celcious;
	
	puts("Introduzca los grados celcious");
	scanf("%d", &celcious);
	
	fahrenheit = (9/5)*(celcious + 32);
	
	printf("%d celcious a fahrenheit es %d\n", celcious, fahrenheit);
	return 0;
}
