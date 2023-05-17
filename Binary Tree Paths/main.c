#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
	struct TreeNode	*left;
	struct TreeNode	*right;
	int				val;
};

struct Node
{
	int			data;
	struct Node	*next;
};

void	Append(struct Node	**first, int data)
{
	struct Node *p;

	struct Node	*new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	new->next = NULL;
	if (*first == NULL)
		*first = new;
	else
	{
		p = *first;
		while (p && p->next)
			p = p->next;
		p->next = new;
	}
}

int	getLast(struct Node	*first)
{
	struct Node *p;

	p = first;
	if (p == NULL)
		return (-200);
	while (p->next)
		p = p->next;
	return (p->data);
}

void	RemoveLast(struct Node **first)
{
	struct Node *p;
	struct Node *q;

	p = *first;
	q = NULL;
	while (p->next)
	{
		q = p;
		p = p->next;
	}
	if (p == *first)
	{
		*first = NULL;
		free(p);
	}
	else
	{
		q->next = NULL;
		free(p);
	}
}

char	*getPath(struct Node	*first)
{
	struct Node	*p;
	char		*path;

	path = (char *)malloc(sizeof(char) * 400);
	strcpy(path, "");
	p = first;
	while (p)
	{
		char	dataStr[5];
		sprintf(dataStr, "%d", p->data);
		strcat(path, dataStr);
		if (p->next)
			strcat(path, "->");
		p = p->next;
	}
	return (path);
}

void	extractPaths(struct TreeNode *p, struct Node **first, char **ans, int *index)
{
	if (p == NULL)
		return;
	if (p->left == NULL && p->right == NULL)
	{
		Append(first, p->val);
		ans[(*index)++] = getPath(*first);
		RemoveLast(first);
		
	}
	Append(first, p->val);
	extractPaths(p->left, first, ans, index);
	extractPaths(p->right, first, ans, index);
	RemoveLast(first);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
	int 	index;
	char	**ans;
	struct	Node	*first;

	index = 0;
	first = NULL;
	ans = (char **)malloc(sizeof(char *) * 100);
	extractPaths(root, &first, ans, &index);
	*returnSize = index;
	return (ans);
}

int main(void)
{
	struct TreeNode *root;
	char			**ans;
	int				returnSize;

	// root = [1,2,3,4]
	root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = 1;
	root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->left->val = 2;
	root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->right->val = 3;
	root->right->left = NULL;
	root->right->right = NULL;
	root->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->left->left->val = 4;
	root->left->right = NULL;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	ans = binaryTreePaths(root, &returnSize);
	for (int i = 0; i < returnSize; i++)
		printf("%s\n", ans[i]);
	return (0);
}