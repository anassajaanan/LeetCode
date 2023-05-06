#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
	struct TreeNode	*left;
	int				val;
	struct TreeNode	*right;
};

bool	isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)
		return (true);
	if ((p && !q) || (!p && q))
		return (false);
	if (p->val != q->val)
		return (false);
	bool res1 = isSameTree(p->left, q->left);
	bool res2 = isSameTree(p->right, q->right);
	return (res1 && res2);
}
