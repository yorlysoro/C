#include <stdio.h>
#include <string.h>
#define TAM 100
int main(void)
{
	char navegador[TAM] = "navegador\n",
	terminal[TAM] = "terminal\n";
	static char entrada[TAM];
	
	
	fgets(entrada,TAM-1,stdin);
	
	if(strcmp(entrada,terminal) == 0)
	{
	  puts("Terminal");
	}
}
