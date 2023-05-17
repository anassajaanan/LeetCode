#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAnagram(char * s, char * t){
	int i;
	int	HT[26];

	if (strlen(s) != strlen(t))
		return (false);
	for (i = 0; i < 26; i++)
		HT[i] = 0;
	for (i = 0; s[i]; i++)
		HT[s[i] - 'a']++;
	for (i = 0; t[i]; i++)
		HT[t[i] - 'a']--;
	for (i = 0; i < 26; i++)
	{
		if (HT[i] != 0)
			return (false);
	}
	return (true);
}