#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
	struct TreeNode	*left;
	int				val;
	struct TreeNode	*right;
};

bool	isSymmetricTree(struct TreeNode	*p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)
		return (true);
	if ((p && !q) || (!p && q))
		return (false);
	if (p->val != q->val)
		return (false);
	bool res1 = isSymmetricTree(p->left, q->right);
	bool res2 = isSymmetricTree(p->right, q->left);
	return (res1 && res2);
}

bool isSymmetric(struct TreeNode* root)
{
	return (isSymmetricTree(root->left, root->right));
}
