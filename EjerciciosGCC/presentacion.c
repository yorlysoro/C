#include <stdio.h>
void contestar(char []);

int main(void)
{
	char nombre[20];
	printf("Hola, me llamo ordenador, y tu?\n");
	scanf("%s", nombre);
	contestar(nombre);
	return 0;
}

void contestar(char *nombre)
{
	printf("Me alegro de conocerte %s\n", nombre);
}
