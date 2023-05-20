#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * reverseWords(char * s)
{
	int i, k = 0;
	int len = strlen(s);
	char *res = (char *)malloc(sizeof(char) * (len + 1));
	int j = len - 1;
	while (j >= 0)
	{
		while (j >= 0 && s[j] == ' ')
			j--;
		if (j < 0 && k > 0 && res[k - 1] == ' ')
		{
			res[k - 1] = '\0';
			return (res);
		}
		while (j >= 0 && s[j] != ' ')
			j--;
		i = j + 1;
		while (i < len && s[i] != ' ')
			res[k++] = s[i++];
		if (j >= 0)
			res[k++] = ' ';
	}
	res[k] = '\0';
	return (res);
}

int main(void)
{
	char *s = "a good   example";
	char *res = reverseWords(s);
	printf("%s\n", res);
	return (0);
}