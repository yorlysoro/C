#include <stdio.h>
#define meses 12
int main(void)
{
	int mes[meses] = {31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31};
	int mesnum;
	puts("Introduzca el numero del mes");
	scanf("%d", &mesnum);
	
	switch(mesnum)
	{
		case 1: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 2: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 3: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 4: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 5: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 6: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 7: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 8: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 9: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 10: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 11: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		case 12: printf("Este mes tiene %d dias\n", mes[mesnum - 1]); break;
		default : puts("Error!"); break;
	}
	return 0;
}
