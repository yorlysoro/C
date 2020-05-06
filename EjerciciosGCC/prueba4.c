#include<stdio.h>


int main(void)
{
	int nums[7] = { 0,1,2,3,4,5};
	int *pnums;
	int i;
	///printf("%d\n",*pnums );
	for(i = 0; i < 6;i++)
	{
		pnums = &nums[i];
		printf("%d", *pnums);
		printf("(%p) ", &pnums);
	}
	printf("\n1 (%p)", *&pnums+1);
	return 0;
}
