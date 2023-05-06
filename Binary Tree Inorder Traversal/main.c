#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
	struct TreeNode	*left;
	int				val;
	struct TreeNode	*right;	
};

int countTotalNode(struct TreeNode *p) // Counts the total number of nodes in the tree.
{
    int x;
    int y;

    if (p)
    {
        x = countTotalNode(p->left);
        y = countTotalNode(p->right);
        return (x + y + 1);
    }
    return (0);
}

void	Inorder(struct TreeNode *root, int *nums, int *index)
{
	if (root)
	{
		Inorder(root->left, nums, index);
		nums[(*index)++] = root->val;
		Inorder(root->right, nums, index);
	}
}

int	*inorderTraversal(struct TreeNode *root, int *returnSize)
{
	int	*nums;
	int	index;

	index = 0;
	*returnSize = countTotalNode(root);
	nums = (int *)malloc(sizeof(int) * (*returnSize));
	Inorder(root, nums, &index);
	return (nums);
}
