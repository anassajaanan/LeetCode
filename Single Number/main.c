#include <stdio.h>
#include <stdlib.h>

int getMax(int *nums, int numsSize)
{
	int max;

	max = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] > max)
			max = nums[i];
	}
	return (max);
}

int getMin(int *nums, int numsSize)
{
	int min;

	min = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] < min)
			min = nums[i];
	}
	return (min);
}

int	singleNumber(int *nums, int numsSize)
{
	int	i;
	int	*HT;
	int max;
	int min;

	max = getMax(nums, numsSize);
	min = getMin(nums, numsSize);
	HT = (int *)malloc(sizeof(int) * (max - min + 1));
	for (i = 0; i <= max - min; i++)
		HT[i] = 0;
	for (i = 0; i < numsSize; i++)
		HT[nums[i] - min]++;
	for (i = 0; i <= max - min; i++)
	{
		if (HT[i] == 1)
			break;
	}
	free(HT);
	return (i + min);
}
