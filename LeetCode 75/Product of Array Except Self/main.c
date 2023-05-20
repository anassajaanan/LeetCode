#include <stdlib.h>
#include <stdio.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	int *answer = (int *)malloc(sizeof(int) * numsSize);

	int prefix = 1;
	for (int i = 0; i < numsSize; i++)
	{
		answer[i] = prefix;
		prefix *= nums[i];
	}
	int suffix = 1;
	for (int i = numsSize - 1; i >= 0; i--)
	{
		answer[i] *= suffix;
		suffix *= nums[i];
	}
	return (answer);
}


int main(void)
{
	int	nums[4] = {1, 2, 3, 4};
	int	numsSize = 4;
	int	returnSize;

	int *ans = productExceptSelf(nums, numsSize, &returnSize);
	for (int i = 0; i < returnSize; i++)
		printf("%d ", ans[i]);
}