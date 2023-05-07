#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	struct TreeNode	*left;
	struct TreeNode	*right;
	int				val;
};

int countNodes(struct TreeNode *p)
{
	int	x;
	int y;

	if (p)
	{
		x = countNodes(p->left);
		y = countNodes(p->right);
		return (x + y + 1);
	}
	else
		return (0);
}

void	Preorder(struct TreeNode *p, int *pre, int *index)
{
	if (p)
	{
		pre[(*index)++] = p->val;
		Preorder(p->left, pre, index);
		Preorder(p->right, pre, index);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int	*pre;
	int index;

	*returnSize = countNodes(root);
	index = 0;
	pre = (int *)malloc(sizeof(int) * (*returnSize));
	Preorder(root, pre, &index);
	return (pre);
}
