#include <stdlib.h>
#include <string.h>

char	*mergeAlternately(char * word1, char * word2){
	int i = 0, j = 0, k = 0;
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	char	*ans = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	int min_len = len1 < len2 ? len1 : len2;
	while (i < min_len)
	{
		ans[k] = word1[i++];
		k += 2;
	}
	k = 1;
	while (j < min_len)
	{
		ans[k] = word2[j++];
		k += 2;
	}
	k--;
	while (i < len1)
	{
		ans[k++] = word1[i++];
	}
	while (j < len2)
	{
		ans[k++] = word2[j++];
	}
	ans[len1 + len2] = '\0';
	return (ans);
}