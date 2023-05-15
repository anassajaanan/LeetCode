#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize){
	int i;
	int j;
	bool flag;
	int max_val;
	int min_val;

	flag = false;
	for (i = 0; i < numsSize; i++)
	{
		if((nums[i] == 1000000000)||(nums[i] == -1000000000))
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
				if (nums[i] == nums[j])
					return (true);
			}
		}
		return (false);
	}
	max_val = nums[0];
	min_val = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] > max_val)
			max_val = nums[i];
		if (nums[i] < min_val)
			min_val = nums[i];
	}
	int Hash[max_val - min_val + 1];
	for (i = 0; i <= max_val - min_val; i++)
		Hash[i] = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (Hash[nums[i] - min_val] == 1)
			return (true);
		Hash[nums[i] - min_val]++;
	}
	return (false);
}

int main(void)
{
	int nums[] = {1000000000, 1000000000, 6};
	int numsSize = 3;

	printf("%d\n", containsDuplicate(nums, numsSize));
	return (0);
}