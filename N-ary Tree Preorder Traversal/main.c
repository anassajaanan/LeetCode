#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void	getPreorder(struct Node *p, int *ans, int *index)
{
	if (p)
	{
		ans[(*index)++] = p->val;
		for (int i = 0; i < p->numChildren; i++)
		{
			getPreorder(p->children[i], ans, index);
		}
	}
}

int* preorder(struct Node* root, int* returnSize) {
	int index;
    int *ans;

	index = 0;
	ans = (int *)malloc(sizeof(int) * 10000);
	getPreorder(root, ans, &index);
	*returnSize = index;
	return (ans);
}

