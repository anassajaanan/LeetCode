#include <stdio.h>

int lengthOfLastWord(char *s){
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
		i++;
	i--;
	while (i >= 0 && s[i] == ' ')
		i--;
	while (i >= 0 && s[i] != ' ')
	{
		count++;
		i--;
	}
	return(count);
}
