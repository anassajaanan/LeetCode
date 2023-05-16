#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	char		data;
	struct node *next;
};

void	push(struct node **top, char data)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

void	pop(struct node **top)
{
	struct node *tmp = *top;
	*top = (*top)->next;
	free(tmp);
}

bool isValid(char *s)
{
	struct node *top;

	top = NULL;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			push(&top, s[i]);
		else
		{
			if (top == NULL)
				return (false);
			if (s[i] == ')' && top->data != '(')
				return (false);
			else if (s[i] == ']' && top->data != '[')
				return (false);
			else if (s[i] == '}' && top->data != '{')
				return (false);
			pop(&top);
		}
	}
	if (top != NULL)
		return (false);
	return (true);
}

int main(void)
{
	char s[] = "{()[]{}";
	printf("%d\n", isValid(s));
	return (0);
}