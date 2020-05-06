#include <stdio.h>

int main(int argc, char *argv[])
{
	int ent[4];
	unsigned char ip[4];
	
	if(argc != 2)
	{
		printf("Uso: %s dir_ip\n", argv[0]);
		exit(0);
	}
	else if(sscanf(argv[1], "%d.%d.%d.%d", ent, ent+1, ent+2, ent+3) != 4)
	{
		printf("Direccion IP incorrecta\n");
		exit(0);
	}
	for(int i = 0; i < 4; i++ )
	{
		ip[i] = ent[i];
		printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
	}
	return 0;
}
