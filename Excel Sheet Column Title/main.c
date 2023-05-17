#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*convertToTitle(int columnNumber)
{
	int		index;
	char	*ans;

	index = 0;
	ans = (char *)malloc(sizeof(char) * 8);
	while (columnNumber > 0)
	{
		ans[index++] = (char)((columnNumber - 1) % 26 + 'A');
		columnNumber = (columnNumber - 1) / 26;
	}
	ans[index] = '\0';
	int i = 0;
	int len = strlen(ans);
	while (i < len / 2)
	{
		char temp = ans[i];
		ans[i] = ans[len - 1 - i];
		ans[len - 1 - i] = temp;
		i++;
	}
	return (ans);
}

int main(void)
{
	int columnNumber = 52;
	char *ans = convertToTitle(columnNumber);
	printf("%s\n", ans);
	free(ans);
	return (0);
}



