#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode	*LLRotation(struct TreeNode **root, struct TreeNode *p)
{
	struct TreeNode *pl;
	struct TreeNode *plr;

	if (p == NULL)
		return (NULL);
	if (p->left == NULL)
		return (p);
	pl = p->left;
	plr = pl->right;
	pl->right = p;
	p->left = plr;
	if (p == *root)
		*root = pl;
	return (pl);
}

struct TreeNode* increasingBST(struct TreeNode* root){
	struct TreeNode *p;

	if (root == NULL)
		return (NULL);
	while (root->left)
		LLRotation(&root, root);
	p = root;
	while (p->right)
	{
		while (p->right->left != NULL)
			p->right = LLRotation(&root, p->right);
		p = p->right;
	}
	return (root);
}

int main(void)
{
	// BST example 2 -> left 1 and 2->right 3
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	struct TreeNode *left = malloc(sizeof(struct TreeNode));
	struct TreeNode *right = malloc(sizeof(struct TreeNode));
	root->val = 2;
	root->left = left;
	root->right = right;
	left->val = 1;
	left->left = NULL;
	left->right = NULL;
	right->val = 3;
	right->left = NULL;
	right->right = NULL;

	root = increasingBST(root);
	printf("%d\n", root->val);
	printf("%d\n", root->right->val);
	printf("%d\n", root->right->right->val);
	return (0);
	
}