#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int i;
	int size;
	int *A;

	size = digitsSize + 1;
	for (i = 0; i < digitsSize; i++)
	{
		if (digits[i] != 9)
		{
			size = digitsSize;
			break;
		}
	}
	*returnSize = size;
	A = (int *)malloc(sizeof(int) * size);
	if (size == digitsSize)
	{
		i = digitsSize - 1;
		while (i > 0 && digits[i] == 9)
			A[i--] = 0;
		A[i] = digits[i] + 1;
		i--;
		while (i >= 0)
		{
			A[i] = digits[i];
			i--;
		}
	}
	else
	{
		A[0] = 1;
		for (i = 1; i < size; i++)
			A[i] = 0;
	}
	return (A);
}


int main(void)
{
	int digits[] = {1, 9, 9, 9, 9, 9, 9, 9, 9};
	int digitsSize = 9;
	int returnSize;
	int *A;

	A = plusOne(digits, digitsSize, &returnSize);
	for (int i = 0; i < returnSize; i++)
		printf("%d ", A[i]);
	printf("\n");
	return (0);
}