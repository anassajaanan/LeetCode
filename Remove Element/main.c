#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < numsSize)
	{
		if (nums[i] != val)
			nums[k++] = nums[i++];
		else
			i++;
	}
	return (k);
}
