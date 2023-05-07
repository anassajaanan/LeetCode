#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	struct TreeNode	*left;
	struct TreeNode	*right;
	int val;
};

struct TreeNode* invertTree(struct TreeNode* root)
{
	struct TreeNode	*temp;

	if (root == NULL)
		return (NULL);
	temp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(temp);
	return (root);
}
