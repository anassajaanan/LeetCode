#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
	int i;
	int j;
	int k;
	int *HT;

	HT = (int *)malloc(sizeof(int) * numsSize);
	for (i = 0; i < numsSize; i++)
		HT[i] = 0;
	for (i = 0; i < numsSize; i++)
		HT[nums[i] - 1]++;
	for (i = 0, k = 0; i < numsSize; i++)
	{
		if (HT[i] == 0)
			nums[k++] = i + 1;
	}
	*returnSize = k;
	free(HT);
	return (nums);
}

int main(void)
{
	int nums[] = {4,3,2,7,8,2,3,1};
	int numsSize = 8;
	int returnSize;
	int *ans;
	int i;

	ans = findDisappearedNumbers(nums, numsSize, &returnSize);
	for (i = 0; i < returnSize; i++)
		printf("%d ", ans[i]);
	return (0);
}