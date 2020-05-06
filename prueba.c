#include <stdio.h>
#include <stdlib.h>
#define BUF 1

int main(void)
{
     char palabra[BUF];
	puts("palabra:");
	fgets(palabra, BUF, stdin);
	while(getchar() != '\n');
	printf("Palabra como caracter: %c\n", palabra[0]);


	return 0;
}
