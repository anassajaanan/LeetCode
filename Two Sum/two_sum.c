#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Brute force Solution

// int	*twoSum(int *nums, int numsSize, int target, int *returnSize)
// {
// 	int	*output;

// 	*returnSize = 2;
// 	output = (int *)malloc(sizeof(int) * 2);
// 	for (int i = 0; i < numsSize - 1; i++)
// 	{
// 		for (int j = i + 1; j < numsSize; j++)
// 		{
// 			if (nums[i] + nums[j] == target)
// 			{
// 				output[0] = i;
// 				output[1] = j;
// 				return (output);
// 			}
// 		}
// 	}
// 	return (output);
// }

// Second Solution


int	get_max(int *nums, int numsSize)
{
	int max;

	max = -2147483648;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] > max)
			max = nums[i];
	}
	return (max);
}

int get_min(int *nums, int numsSize)
{
	int min;

	min = 2147483647;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] < min)
			min = nums[i];
	}
	return (min);
}

int	*twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int *output;
	int max = get_max(nums, numsSize);
	int min = get_min(nums, numsSize);
	int hashMap[max - min + 1];

	output = (int *)malloc(sizeof(int) * 2);
	for (int i = 0; i < max - min + 1; i++)
		hashMap[i] = -1;
	for (int i = 0; i < numsSize; i++)	{
		hashMap[nums[i] - min] = i;
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (hashMap[target - nums[i] - nums[i]] >= 0)
		{
			output[0] = hashMap[nums[i] - min];
			output[1] = hashMap[target - nums[i] - nums[i]];
			return (output);
		}
	}
	return (output);
}

int main(void)
{
	int nums[] = {3, 2 , 4};
	int target = 6;
	int returnSize;
	int *output;

	output = twoSum(nums, 3                    , target, &returnSize);
	printf("%d %d\n", output[0], output[1]);
	free(output);
	return (0);
}