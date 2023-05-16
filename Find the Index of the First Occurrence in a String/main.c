#include <stdio.h>

int strStr(char * haystack, char * needle){
	int i;
	int j;

	for (i = 0; haystack[i]; i++)
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return (i);
	}
	return (-1);
}