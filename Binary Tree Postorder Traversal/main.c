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

void	Postorder(struct TreeNode *p, int *pre, int *index)
{
	if (p)
	{
		Postorder(p->left, pre, index);
		Postorder(p->right, pre, index);
		pre[(*index)++] = p->val;
	}
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	int	*pre;
	int index;

	*returnSize = countNodes(root);
	index = 0;
	pre = (int *)malloc(sizeof(int) * (*returnSize));
	Postorder(root, pre, &index);
	return (pre);
}
