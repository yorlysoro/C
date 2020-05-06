#include <stdio.h>

int main(void)
{
	char i, *p;
	
	p=&i;
	
	for(i='a'; i<= 'z';i++)
	{
		printf("%c ", *p);
	}
	putchar('\n');
	for(i='a';i<='z';i++)
	{
		printf("%c ",*p-32);
	}
	return 0;
}
