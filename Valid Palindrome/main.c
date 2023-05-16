#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool	isPalindrome(char *s)
{
	int i = 0;
	int j = strlen(s) - 1;

	while (i < j)
	{
		while (i < j && !isalnum(s[i]))
			i++;
		while (i < j && !isalnum(s[j]))
			j--;
		if (tolower(s[i]) != tolower(s[j]))
			return (false);
		i++;
		j--;	
	}
	return (true);
}

int main(void)
{
	char str[] = "A man, a plan, a canal: Panama";
	printf("%d\n", isPalindrome(str));
	return (0);
}