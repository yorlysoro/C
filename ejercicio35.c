#include <stdio.h>
#define verdad 1 
#define falso 0
int main(void)
{
	int x = 0;
	
	puts("Introduce un numero");
	scanf("%d", &x);
	
	if(x > 10)
	printf("%d", verdad);
	else
	printf("%d", falso);
	
	return 0;
}
