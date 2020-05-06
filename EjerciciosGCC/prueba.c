#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int num = 0;
	char cad[30];
	static char car[3];
	fgets(cad,31,stdin);
	printf("%s", cad);
	
	for(num = 0; num < 30; num++)
	{
		if(cad[num] == 'a')
		car[num] = cad[num];
		if(num > 3)
		break;
	}
	for(num = 0; num < 3; num++)
	{
		putchar(car[num]);
	}
	putchar('\n');
	switch(car[0])
	{
		case 'a':
		printf("Es una %c", car[0]);
		break;
	}
	putchar('\n');
	static char abcd[26];
	//char minus[26];
	
	for(num = 65; num < 90; num++)
	{
		printf("%c ", abcd[num-65] = num);
	}
	putchar('\n');
	for(num = 0; num < 26; num++)
	{
			if( islower(abcd[num]) == 0)
		{
			printf("%c ", abcd[num]+32);
		}
	}
	return 0;
}
