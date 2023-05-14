#include <stdio.h>
#include <stdlib.h>


int memo[100][100] = {0};

int Pascal(int row, int col)
{
	// If col is greater than n, return 0.
	if (col > row)
		return 0;
	// If col is 0 or row, return 1.
	if (col == 0 || col == row)
		return 1;
	// If the value has already been calculated, return it from the memoization table.
	if (memo[row][col] != 0)
		return memo[row][col];
	memo[row][col] = Pascal(row - 1, col - 1) + Pascal(row - 1, col);
	return (memo[row][col]);
}

int* getRow(int rowIndex, int* returnSize)
{
	*returnSize = rowIndex + 1;
	int *row = (int *)malloc(sizeof(int) * (rowIndex + 1));
	row[0] = 1;
	row[rowIndex] = 1;
	for (int i = 1; i < rowIndex; i++)
	{
		row[i] = Pascal(rowIndex, i);
	}
	return (row);
}

int main(void)
{
	int i;
	int *row;
	int returnSize;

	row = getRow(29, &returnSize);
	for (i = 0; i < returnSize; i++)
		printf("%d ", row[i]);
	free(row);
	return (0);
}