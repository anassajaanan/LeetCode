#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char ** summaryRanges(int* nums, int numsSize, int* returnSize){
	int		a;
	int		b;
	char	*res;
	char	**ans;

	if (numsSize == 0)
	{
		*returnSize = 0;
		return (NULL);
	}
	ans = (char **)malloc(sizeof(char *) * (20));
	int i = 0;
	int k = 0;
	while (i < numsSize)
	{
		a = nums[i];
		while (i < numsSize - 1 && (long int)nums[i + 1] - (long int)nums[i] == 1)
			i++;
		b = nums[i];
		if (a == b)
		{
			res = (char *)malloc(sizeof(char) * 20);
			snprintf(res, 20, "%d", a);
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (28));
			snprintf(res, 28, "%d->%d", a, b);
		}
		ans[k++] = res;
		i++;
	}
	*returnSize = k;
	return (ans);
}

int main(void)
{
	int		nums[] = {-2147483648,-2147483647,2147483647};
	int		numsSize = 3;
	int		returnSize;
	char	**ans;
	int		i;

	ans = summaryRanges(nums, numsSize, &returnSize);
	i = 0;
	while (i < returnSize)
	{
		printf("%s\n", ans[i]);
		i++;
	}
	return (0);
}