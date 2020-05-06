#include <stdio.h>


int main(void)
{
	char c,*pc;
	
	pc=&c;
	
	for(c='A';c<='Z';c++)
	{
		printf("%c ", *pc);
		while(getchar() != '\n');
	}
	return 0;
}
