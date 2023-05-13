#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	int index;
	struct Node *next;
};

int hash(int key)
{
	int res;

    res = key % 10;
    if (res < 0)
        return (-res);
    return (res);
}

struct Node	*LinearSearch(struct Node *p, int key) // Linear Search
{
	while (p)
	{
		if (key == p->data)
			return (p);
		else if (key < p->data)
			return (NULL);
		p = p->next;
	}
	return (NULL);
}

void	SortedInsert(struct Node **first, int x, int index)
{
	struct Node *p;
	struct Node *q;
	struct Node *new;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = x;
	new->index = index;
	new->next = NULL;
	p = (*first);
	q = NULL;
	if (p == NULL)
		(*first) = new;
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		new->next = p;
		if (q == NULL)
			(*first) = new;
		else
			q->next = new;
	}
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int			i;
	int			*ans;
	struct Node	*p;
	struct Node **HT;

	*returnSize = 2;
	ans = (int *)malloc(sizeof(int) * 2);
	HT = (struct Node **)malloc(sizeof(struct Node *) * 10);
	for (i = 0; i < 10; i++)
		HT[i] = NULL;
	for (i = 0; i < numsSize; i++)
	{
		p = LinearSearch(HT[hash(target - nums[i])], target - nums[i]);
		if (p == NULL)
			SortedInsert(&HT[hash(nums[i])], nums[i], i);
		else
		{
			ans[1] = i;
			ans[0] = p->index;
			free(HT);
			break;
		}
	}
	return (ans);
}

int main(void)
{
	int		nums[3] = {3,4, -3};
	int		numsSize = 3;
	int		target = 0;
	int		*ans;
	int		returnSize;

	ans = twoSum(nums, numsSize, target, &returnSize);
	printf("%d %d\n", ans[0], ans[1]);
	return (0);
}