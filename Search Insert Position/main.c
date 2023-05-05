#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
	int	f = 0;
	int	l = numsSize - 1;
	int mid;

	while (f <= l)
	{
		mid = (l + f + 1) / 2;
		if (nums[mid] == target) return (mid);
		else if (target < nums[mid]) l = mid - 1;
		else f = mid + 1;
	}
	return (f);
}



// int main(void)
// {
// 	int nums[] = {1, 3};
// 	int numsSize = 2;
// 	int target = 4;

// 	printf("%d\n", searchInsert(nums, numsSize, target));
// }