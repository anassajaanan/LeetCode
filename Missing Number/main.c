#include <stdio.h>

int	calculateSum(int *nums, int numsSize)
{
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
		sum += nums[i];
	return (sum);
}

int missingNumber(int *nums, int numsSize)
{
	return ((numsSize * (numsSize + 1) / 2) - calculateSum(nums, numsSize));
}




// int main(void)
// {
// 	int nums[] = {3, 0, 1};
// 	int numsSize = 3;
// 	int ret = missingNumber(nums, numsSize);
// 	printf("%d\n", ret);
// }