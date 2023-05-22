#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * removeOuterParentheses(char *s)
{
	int len = strlen(s);
	char *ans = (char *)malloc(sizeof(char) * len);
	int k = 0, l = 0, r = 0;
	for (int i = 0; i < len; i++)
	{
		if (l == r)
		{
			l = 0;
			r = 0;
		}
		if (s[i] == '(')
			l++;
		else if (s[i] == ')')
			r++;
		if (r != l && l != 1)
			ans[k++] = s[i];
	}
	ans[k] = '\0';
	return (ans);
}

int main(void)
{
	char s[] = "(()())(())(()(()))";
	printf("%s\n", removeOuterParentheses(s));
	return (0);
}