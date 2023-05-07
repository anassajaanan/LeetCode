#include <stdio.h>

struct TreeNode
{
	struct TreeNode	*left;
	int				val;
	struct TreeNode	*right;
};

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return (0);
	int x = maxDepth(root->left);
	int y = maxDepth(root->right);
	if (x > y){
		return (x + 1);
	}else{
		return (y + 1);
	}
}