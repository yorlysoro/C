#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ind, cont_num = 0, cont_text = 0;
	char temp;
	char cadena[6];
	
	printf("Introducir 5 caracterres: ");
	gets(cadena);
	
	for(ind = 0; ind<5; ind++)
	{
		temp=isalpha(cadena[ind]);
		if(temp)
		cont_text++;
		else
		cont_num++;
	}
	
	printf("El total de letras es %d\n", cont_text);
	printf("El total de numeros es %d\n", cont_num);
	return 0;
}
