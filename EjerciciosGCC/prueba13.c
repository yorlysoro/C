#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char entrada[50];
	int i, num[50];
	
	fgets(entrada,50,stdin);
	for(i = 0; i < 50; i++)
	{
		if(entrada != '\0')
		{
			if(isdigit(entrada[i]) != 0)
			{
				puts("Es un digito");
				printf("el numero es %d\n", num[i]= atoi(entrada[i]));
				
			}
		}
	}
	*entrada = (char)*num;
	printf("como caracter es %s\n", entrada);
	return 0;
}
