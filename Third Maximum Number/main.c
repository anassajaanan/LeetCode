#include <stdio.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int thirdMax(int* nums, int numsSize){
	int i;
	int j;
	int flag;
	int max_val;
	int min_val;
	int first_max;

	flag = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == -2147483648 || nums[i] == 2147483647)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		for (i = 0; i < numsSize - 1; i++)
		{
			for (j = 0; j < numsSize - 1 - i; j++)
			{
				if (nums[j] > nums[j + 1])
					swap(&nums[j], &nums[j + 1]);
			}
		}
		j = 0;
		i = numsSize - 1;
		while (i >= 0)
		{
			j++;
			if (j == 3)
				return (nums[i]);
			while (i > 0 && nums[i] == nums[i - 1])
				i--;
			i--;
		}
		return (nums[numsSize - 1]);
	}
	max_val = nums[0];
	min_val = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] > max_val)
			max_val = nums[i];
		if (nums[i] < min_val)
			min_val = nums[i];
	}
	int HT[max_val - min_val + 1];
	for (i = 0; i <= max_val - min_val; i++)
		HT[i] = 0;
	for (i = 0; i < numsSize; i++)
		HT[nums[i] - min_val]++;
	i = max_val - min_val;
	j = 0;
	while (i >= 0)
	{
		if (HT[i] != 0)
		{
			if (j == 0)
				first_max = i + min_val;
			j++;
		}
		if (j == 3)
			return (i + min_val);
		i--;
	}
	return (first_max);
}

int thirdMax(int* nums, int numsSize)
{
	int i;
	int j;

	for (i = 0; i < numsSize - 1; i++)
	{
		for (j = 0; j < numsSize - 1 - i; j++)
		{
			if (nums[j] > nums[j + 1])
				swap(&nums[j], &nums[j + 1]);
		}
	}
	j = 0;
	i = numsSize - 1;
	while (i >= 0)
	{
		j++;
		if (j == 3)
			return (nums[i]);
		while (i > 0 && nums[i] == nums[i - 1])
			i--;
		i--;
	}
	return (nums[numsSize - 1]);
}

int main(void)
{
	int nums[] = {1, 2, 2, 5, 3, 5};
	int numsSize = 5;

	printf("%d\n", thirdMax(nums, numsSize));
	return (0);
}