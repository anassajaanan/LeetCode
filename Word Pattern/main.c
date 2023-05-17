#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int	countWords(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (isalpha(str[i]) && !isalpha(str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	**split(char *str, int number_words)
{
	int i = 0, j, k, l = 0;
	char	*word;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * number_words);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			j = i;
			while (str[j] && (str[j] >= 'a' && str[j] <= 'z'))
				j++;
			word = (char *)malloc(sizeof(char) * (j - i + 1));
			k = 0;
			while (i < j)
				word[k++] = str[i++];
			word[k] = '\0';
			strs[l++] = word;
		}
	}
	return (strs);
}

bool wordPattern(char *pattern, char *s){
	int 	i, j, k;
	int 	number_words;
	char	**strs;

	number_words = countWords(s);
	if (strlen(pattern) != number_words)
		return (false);
	strs = split(s, number_words);
	char	*HT[26];
	for (i = 0; i < 26; i++)
		HT[i] = NULL;
	for (i = 0; pattern[i]; i++)
	{
		if (HT[pattern[i] - 'a'] == NULL)
			HT[pattern[i] - 'a'] = strs[i];
		else
		{
			if (strcmp(HT[pattern[i] - 'a'], strs[i]) != 0)
				return (false);
		}
	}
	char	*HT2[number_words];
	j = 0;
	for (i = 0; i < 26; i++)
	{
		if (HT[i] != NULL)
			HT2[j++] = HT[i];
	}
	for (i = 0; i < j - 1; i++)
	{
		for (k = i + 1; k < j; k++)
		{
			if (strcmp(HT2[i], HT2[k]) == 0)
				return (false);
		}
	}
	return (true);
}

int main(void)
{
	char	*pattern = "abcdefghijklmnnmlkjihgfedcba";
	char	*s = "aa bb cc dd ee ff gg hh ii jj kk ll mm nn nn mm ll kk jj ii hh gg ff ee dd cc bb aa";
	printf("%d\n", wordPattern(pattern, s));
	return (0);

}