#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
	int i;
	int k;
	int	B[numsSize];

	i = 0;
	k = 0;
	while (i < numsSize)
	{
		B[k++] = nums[i++];
		while (i < numsSize && nums[i] == nums[i - 1])
			i++; 
	}
	for (i = 0; i < k; i++)
		nums[i] = B[i];
	return (k);
}

int main(void)
{
	int nums[10] = {0,0,1,1,1,2,2,3,3,4};
	int numsSize = 10;
	int i;

	i = removeDuplicates(nums, numsSize);
	printf("%d\n", i);

	for (int j = 0; j < numsSize; j++)
		printf("%d ", nums[j]);
	return (0);
}