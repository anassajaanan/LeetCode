#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char *columnTitle){
	int A[8];
	int i;
	int len;
	int res;

	res = 0;
	i = 0;
	len = strlen(columnTitle);
	while (i < len / 2)
	{
		char temp = columnTitle[i];
		columnTitle[i] = columnTitle[len - 1 - i];
		columnTitle[len - 1 - i] = temp;
		i++;
	}
	for (i = 0; columnTitle[i]; i++)
		A[i] = (columnTitle[i] - 'A') % 26 + 1;
	for (int j = 0; j < i; j++)
	{
		int n = A[j];
		for (int k = 0; k < j; k++)
			n *= 26;
		res += n;
	}
	return (res);
}

int main(void)
{
	char s[] = "FXSHRXW";
	printf("%d\n", titleToNumber(s));
	return (0);
}