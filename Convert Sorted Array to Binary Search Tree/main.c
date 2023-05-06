#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
	struct TreeNode	*left;
	int				val;
	struct TreeNode	*right;
};

struct TreeNode	*createBST(int *nums, int start, int end)
{
	struct TreeNode	*t;
	int 			mid;

	if (start <= end)
	{
		mid = (start + end + 1) / 2;
		t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		t->val = nums[mid];
		t->left = createBST(nums, start, mid - 1);
		t->right = createBST(nums, mid + 1, end);
		return (t);
	}
	else
		return (NULL);
}

struct TreeNode	*sortedArrayToBST(int *nums, int numsSize)
{
	return (createBST(nums, 0, numsSize - 1));
}





/*
void	displayTree(struct TreeNode *root, int level)
{
	if (root)
	{
		displayTree(root->right, level + 1);
		for (int i = 0; i < level; i++)
			printf("    ");
		printf("%d\n", root->val);
		displayTree(root->left, level + 1);
	}
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7};
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	struct TreeNode *root = sortedArrayToBST(nums, numsSize);

	displayTree(root, 0);
}
*/
