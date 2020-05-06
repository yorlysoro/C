#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0; num1 = 0; repe, temp;
	int valores[6];
	
	printf("Loteria primitiva: ");
	randomize();
	
	for(;;)
	{
		repe=1;
		if(num == 6)
		break;
		temp = random(49) + 1;
		for(num1 = 0; num1 < num; num1++)
		{
			if(valores[num1] == temp)
			{
				valores[num1] = temp;
				num--;
				repe=0;
				break;
			}
		}
		if(repe==1)
		valores[num] = temp;
		
		num++;
	}
	for(num = 0; num < 6; num++)
	printf("%d", valores[num]);
	return 0;
}
