#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	int i;
	int j;
	int *row;
	int **A;

	*returnSize = numRows;
	*returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
	A = (int **)malloc(sizeof(int *) * numRows);
	for (i = 0; i < numRows; i++)
	{
		row = (int *)malloc(sizeof(int) * (i + 1));
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
				row[j] = 1;
			else
				row[j] = A[i - 1][j - 1] + A[i - 1][j];
		}
		A[i] = row;
		(*returnColumnSizes)[i] = i + 1;
	}
	return (A);
}

int main(void)
{
	int i;
	int j;
	int numRows;
	int returnSize;
	int *returnColumnSizes;
	int **A;

	numRows = 29;
	A = generate(numRows, &returnSize, &returnColumnSizes);
	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < returnColumnSizes[i]; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	return (0);
}