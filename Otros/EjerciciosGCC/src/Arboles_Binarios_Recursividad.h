#include <stdlib.h>
#include <stdio.h>

#define CR printf("\n");

int FnIntFactorial(int xDato)
{
	if(xDato == 0 || xDato == 1)
	{
		printf("%d = ", xDato);
		return 1;
	}
	else
	{
		printf("%d x ", xDato);
		return xDato *FnIntFactorial(xDato-1);
	}
}
