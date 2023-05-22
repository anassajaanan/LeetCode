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

int main(void)
{
	struct Node *root;
	int *ans;
	int returnSize;

	root = (struct Node *)malloc(sizeof(struct Node));
	root->val = 1;
	root->numChildren = 3;
	root->children = (struct Node **)malloc(sizeof(struct Node *) * 3);
	root->children[0] = (struct Node *)malloc(sizeof(struct Node));
	root->children[0]->val = 3;
	root->children[0]->numChildren = 2;
	root->children[0]->children = (struct Node **)malloc(sizeof(struct Node *) * 2);
	root->children[0]->children[0] = (struct Node *)malloc(sizeof(struct Node));
	root->children[0]->children[0]->val = 5;
	root->children[0]->children[0]->numChildren = 0;
	root->children[0]->children[0]->children = NULL;
	root->children[0]->children[1] = (struct Node *)malloc(sizeof(struct Node));
	root->children[0]->children[1]->val = 6;
	root->children[0]->children[1]->numChildren = 0;
	root->children[0]->children[1]->children = NULL;
	root->children[1] = (struct Node *)malloc(sizeof(struct Node));
	root->children[1]->val = 2;
	root->children[1]->numChildren = 0;
	root->children[1]->children = NULL;
	root->children[2] = (struct Node *)malloc(sizeof(struct Node));
	root->children[2]->val = 4;
	root->children[2]->numChildren = 0;
	root->children[2]->children = NULL;
	ans = preorder(root, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", ans[i]);
	}
	return (0);
}