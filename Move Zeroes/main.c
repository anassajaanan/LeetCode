#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
	int i;
	int k;

	for (i = 0, k = 0; i < numsSize; i++)
	{
		if (nums[i] != 0)
			nums[k++] = nums[i];
	}
	while (k < numsSize)
		nums[k++] = 0;
}
