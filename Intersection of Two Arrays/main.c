#include <stdlib.h>
#include <stdio.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int i;
	int k;
	int	*ans;

	ans = (int *)malloc(sizeof(int) * (1000));
	int HT[1001];
	for (i = 0; i <= 1000; i++)
		HT[i] = -1;
	for (i = 0; i < nums1Size; i++)
	{
		if (HT[nums1[i]] == -1)
			HT[nums1[i]] = 1;
	}
	for (i = 0, k = 0; i < nums2Size; i++)
	{
		if (HT[nums2[i]] == 1)
		{
			ans[k++] = nums2[i];
			HT[nums2[i]] = 0;
		}
	}
	*returnSize = k;
	return (ans);
}

int main(void)
{
	int nums1[] = {4, 9, 5};
	int nums2[] = {9, 4, 9, 8, 4};
	int nums1Size = 3;
	int nums2Size = 5;
	int returnSize;
	int *ans;
	int i;

	ans = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
	for (i = 0; i < returnSize; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return (0);
}