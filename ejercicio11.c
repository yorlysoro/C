#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *c;
	int t;
	c = malloc(80);
	if(!c)
	{
		printf("Fallo al asignar memoria");
		exit(1);
	}
	printf("Introducir cadena: ");
	gets(c);
	for(t = strlen(c)-1; t >= 0; t--)
		putchar(c[t]);
	free(c);
	return 0;
}
