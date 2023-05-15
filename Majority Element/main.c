#include <stdlib.h>
#include <stdio.h>

int majorityElement(int *nums, int numsSize) // Moore voting algorithm
{
	int count;
	int maj_index;

	count = 1;
	maj_index = 0;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] == nums[maj_index])
			count++;
		else
			count--;
		if (count == 0)
		{
			maj_index = i;
			count = 1;
		}
	}
	return (nums[maj_index]);
}
