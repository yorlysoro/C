#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("Error en n de argumentos");
		exit(0);
	}
	printf("Suma de valores\n");
	printf("Total = %d\n", atoi(argv[1]) + atoi(argv[2]));
	return 0;
}
