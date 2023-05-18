#include <stdio.h>
#include <string.h>

int firstUniqChar(char *s){
	int i;
	int len = strlen(s);
	int	HT[26] = {0};

	for (i = 0; i < len; i++)
		HT[s[i] - 'a']++;
	for (i = 0; i < len; i++)
	{
		if (HT[s[i] - 'a'] == 1)
			return (i);
	}
	return (-1);
}
