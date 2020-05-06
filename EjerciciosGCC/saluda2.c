#include <stdio.h>

void contestar(char []);

int main(void)
{
	char nombre[20];
	printf("Hola, me llamo Iagoba, y tu?\n");
	gets(nombre);
	contestar(nombre);
	return 0;
}

void contestar(char *nombre)
{
	printf("Me alegro de conocerte %s\n", nombre);
}
