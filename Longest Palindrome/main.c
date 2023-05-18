#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int longestPalindrome(char * s){
	int len = 0;
	int len_s = strlen(s);
	int HT[58] = {0};
	for (int i =0; i < len_s; i++)
	{
		HT[s[i] - 'A']++;
	}
	for (int i = 0; i < len_s; i++)
	{
		if (HT[s[i] - 'A'] % 2 == 0)
		{
			len += HT[s[i] - 'A'];
			HT[s[i] - 'A'] = 0;
		}
		else if (HT[s[i] - 'A'] > 2)
		{
			len += HT[s[i] - 'A'] - 1;
			HT[s[i] - 'A'] = 1;
		}
	}
	for (int i = 0; i < len_s; i++)
	{
		if (HT[s[i] - 'A'] == 1)
		{
			len += 1;
			break;
		}
	}
	return (len);
}
