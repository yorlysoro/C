#include <stdio.h>

int main(void)
{
	float lb;
	
	printf("\nIntroduzca el peso en libras: ");
	scanf("%f", &lb);
	printf("\nEl peso en kilogramos es: %.2f kg", lb*0.453592);
	printf("\nEl peso en gramos es: %.2f g", lb*453.59237);
	
	return 0;
}
