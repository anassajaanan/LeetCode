#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i;
	int j;
	int flag;
	int max_val;
	int min_val;

	flag = false;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == 1000000000 || nums[i] == -1000000000)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		for (i = 0; i < numsSize - 1; i++)
		{
			for (j = i + 1; j < numsSize; j++)
			{
				if (nums[i] == nums[j] && abs(i - j) <= k)
					return (true);
			}
		}
		return (false);
	}
	max_val = nums[0];
	min_val = nums[0];
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > max_val)
			max_val = nums[i];
		if (nums[i] < min_val)
			min_val = nums[i];
	}
	int HT[max_val - min_val + 1];
	for (i = 0; i <= max_val - min_val; i++)
		HT[i] = -1;
	for (i = 0; i < numsSize; i++)
	{
		if (HT[nums[i] - min_val] == -1)
			HT[nums[i] - min_val] = i;
		else
		{
			if (abs(i - HT[nums[i] - min_val]) <= k)
				return (true);
			else
				HT[nums[i] - min_val] = i;
		}
	}
	return (false);
}
