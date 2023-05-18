#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
	int 	max;
	bool	*result;

	max = candies[0];
	for (int i = 1; i < candiesSize; i++)
	{
		if (candies[i] > max)
			max = candies[i];
	}
	result = (bool *)malloc(sizeof(bool) * candiesSize);
	for (int i = 0; i < candiesSize; i++)
	{
		if (candies[i] + extraCandies >= max)
			result[i] = true;
		else
			result[i] = false;
	}
	*returnSize = candiesSize;
	return (result);
}

int main(void)
{
	int candies[] = {4,2,1,1,2};
	int candiesSize = 5;
	int extraCandies = 1;
	int returnSize;
	bool *result;

	result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	return (0);
}