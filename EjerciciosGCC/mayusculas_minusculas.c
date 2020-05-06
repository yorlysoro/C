#include <stdio.h>
#include <ctype.h>
#define MAXCADENA 20

char *ConversionLetra(char *cadena);

int main(void)
{
	char tmp[MAXCADENA+1];
	
	printf("\nEscriba una cadena (de %d caracteres maximo) y tecle intro\n", MAXCADENA);
	gets(tmp);
	printf("\n%s\n", ConversionLetra(tmp));
	return 0;
}

char *ConversionLetra(char *cadena)
{
	char *pc;
	pc = cadena;
	*pc = toupper(*pc);
	++pc;
	while(*pc != '\0')
	{
		*pc = tolower(*pc);
		++pc;
	}
	return(cadena);
}
