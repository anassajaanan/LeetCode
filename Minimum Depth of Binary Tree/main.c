#include <stdio.h>

struct TreeNode
{
	struct TreeNode	*left;
	struct TreeNode	*right;
	int				val;
};

int minDepth(struct TreeNode* root)
{
	if (root == NULL)
		return (0);
	if (root->left == NULL && root->right == NULL)
		return (1);
	if (root->left == NULL)
		return (minDepth(root->right) + 1);
	if (root->right == NULL)
		return (minDepth(root->left) + 1);
	int x = minDepth(root->left);
	int y = minDepth(root->right);
	if (x < y)
		return (x + 1);
	else
		return (y + 1);
}