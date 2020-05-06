#include <stdio.h>

int main(void)
{
	int i;
	float c;
	for(i=0;i<=300;i+=20)
	{
			c=(5./9)*(i-32);
			printf("%3d grados en farenheit equivalen a %4.4f grados Celsius\n",i,c);
	}
	return 0;
}
