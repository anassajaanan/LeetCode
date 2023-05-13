#include <stdlib.h>
#include <stdio.h>


struct TreeNode
{
	struct TreeNode *left;
	struct TreeNode *right;
	int				val;
};

int countPaths(struct TreeNode *p)
{
	if (p)
	{
		int x = countPaths(p->left);
		int y = countPaths(p->right);
		if (x == 0 && y == 0)
			return (1);
		if (x == y)
			return (x + y);
		return (x > y ? x : y);
	}
	else
		return (0);
}

