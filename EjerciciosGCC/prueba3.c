#include <stdio.h>
void numeros(int num, int num2);

int main(void)
{
	int tam = sizeof(int);
	int tam2;
	int num = 2;
	int *num1 = &num;
	int **num2 = &num1;
	int ***num3 = &num2;
	int p = ***num3, c = **num2;
	int nums[2][12] = {{1,2,3,4,5,6,7,8,9,10,11}, {1,2,3,4,5,6,7,8,9,10,11}}; 
	tam2 = sizeof(num);
	printf("%d\n", num);
	printf("%d\n", *num1);
	printf("%d\n", **num2);
	printf("%d\n", ***num3);
	
	printf("%p\n", &num);
	printf("%p\n", num1);
	printf("%p\n", num2);
	printf("%p\n", num3);
	
	printf("%d\n", tam);
	printf("%d\n", tam2);
	
	printf("%d\n", *nums[0]);
	printf("%d\n", **nums+2);
	printf("%d\n", *nums[1]+4);
	printf("%d\n", nums[1][4]);
	printf("%d\n", **nums+4);
	printf("%d\n", nums[0][4]);
	
	printf("%p\n", *&nums[0]);
	printf("%p\n", **&nums+2);
	printf("%p\n", *&nums[1]+4);
	printf("%p\n", &nums[1][4]);
	printf("%p\n", **&nums+4);
	printf("%p\n", &nums[0][4]);
	
	numeros(p,c);
	
	return 0;
}

void numeros(int num, int num2)
{
	int result;
	
	result = num * num2;
	printf("%d\n", result);
}
