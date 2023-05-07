#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
	struct TreeNode	*left;
	struct TreeNode	*right;
	int				val;
};

int calculateHeight(struct TreeNode *p)
{
	if (p == NULL)
		return (0);
	int x = calculateHeight(p->left);
	int y = calculateHeight(p->right);
	if (x > y){
		return (x + 1);
	}else{
		return (y + 1);
	}
}

bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
		return (true);
	int bf = calculateHeight(root->left) - calculateHeight(root->right);
	if (bf >= 2 || bf <= -2)
		return (false);
	bool res1 = isBalanced(root->left);
	bool res2 = isBalanced(root->right);
	return (res1 && res2);
}