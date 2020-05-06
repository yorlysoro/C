#include <stdio.h>

int main(void)
{
	char *pc, c;
	pc = &c;
	for(c = 'A'; c <= 'Z'; c++)
	{
		printf("%c ", *pc);
	}
	return 0;
}
