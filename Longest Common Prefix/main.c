#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*longestCommonPrefix(char ** strs, int strsSize){
	int 	i;
	int 	j;
	char	c;
	char	*common_prefix;

	for (i = 0; strs[0][i] != '\0'; i++)
	{
		c = strs[0][i];
		for (j = 1; j < strsSize; j++)
		{
			if (strs[j][i] != c)
				break;
		}
		if (j != strsSize)
			break;
	}
	common_prefix = (char *)malloc(sizeof(char) * (i + 1));
	for (j = 0; j < i; j++)
		common_prefix[j] = strs[0][j];
	common_prefix[j] = '\0';
	return (common_prefix);
}
