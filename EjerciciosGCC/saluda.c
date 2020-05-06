#include <stdio.h>

int main(void)
{
	char nombre[20];
	printf("Hola, me llamo ordenador, y tu?\n");
	scanf("%s", &nombre[0]);
	printf("Me alegro de conocerte %s\n", nombre);
	return 0;
}
