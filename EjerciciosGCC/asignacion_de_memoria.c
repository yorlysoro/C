#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char cad[121], *ptr;
	int lon;
	
	puts("\nIntroduce una cadena");
	fgets(cad,121,stdin);
	lon = strlen(cad);
	ptr = (char *)malloc((lon+1) * sizeof(char));
	
	strcpy(ptr,cad);
	
	printf("Ptr = %s\n", ptr);
	free(ptr);
	return 0;
}
