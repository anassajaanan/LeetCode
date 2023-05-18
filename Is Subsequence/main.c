#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char * s, char * t){
	int i = 0, j = 0;
	int len_s = strlen(s);
	int len_t = strlen(t);
	while (i < len_t && j < len_s)
	{
		if (t[i] == s[j])
		{
			j++;
		}
		i++;
	}
	if (j == len_s)
		return (true);
	return (false);
}

int main(void)
{
	char *s = "axc";
	char *t = "ahbgdc";
	printf("%d\n", isSubsequence(s, t));
	return (0);
}