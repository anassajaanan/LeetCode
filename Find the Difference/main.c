#include <stdio.h>
#include <string.h>

char findTheDifference(char * s, char * t){
	int i;
	int len_s = strlen(s);
	int len_t = strlen(t);
	int HT[26] = {0};
	for (i = 0; i < len_t; i++)
	{
		HT[t[i] - 'a']++;
	}
	for (i = 0; i < len_s; i++)
	{
		HT[s[i] - 'a']--;
	}
	for (i = 0; i < len_t; i++)
	{
		if (HT[t[i] - 'a'] == 1)
			break;
	}
	return (t[i]);
}
