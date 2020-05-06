#include <stdio.h>
const int M = 6;

int main(void)
{
	int a, b, c;
	puts("Introduce el valor de a y b");
	scanf("%d %d", &a, &b);
	c = 2 * a - b;
	c -= M;
	b = a + c - M;
	a = b * M;
	printf("\na = %d\n",a);
	b = -1;
	printf(" %6d %6d\n", b, c);
	return 0;
}
