#include <stdio.h>
#define FILAS 4
#define COLS 5

int main(void)
{
	int j, k;
	int arr1 [FILAS] [COLS] = {{13,15,17,19,21},
								{20,22,24,26,28},
								{31,33,35,37,39},
								{40,42,44,46,48}};
	int arr2 [FILAS] [COLS] = {{10,11,12,13,14},
								{15,16,17,18,19},
								{20,21,22,23,24},
								{25,26,27,28,29}};
	int arr3 [FILAS] [COLS];
	for(j=0; j<FILAS; j++)
	{
		for(k=0; k<COLS; k++)
		{
			*(*(arr3+j)+k) = *(*(arr1+j)+k) + *(*(arr2+j)+k);
			printf("%d ", *(*(arr3+j)+k));
		}
		printf("\n");
	}
	return 0;
}
