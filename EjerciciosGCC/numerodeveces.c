#include <stdio.h>

int main(void)
{
	char ch;
	int num_rep;
	printf("\nEscriba el caracter a repetir: ");
	scanf("%c", &ch);
	printf("\nEscriba el numero de repeticiones: ");
	scanf("%d", &num_rep);
	while(num_rep>0)
	{
		printf("%c", ch);
		--num_rep;
	}
	printf("\n");
	return 0;
}
