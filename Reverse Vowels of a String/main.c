#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	isVowel(char c)
{
	c = tolower(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o')
		return (1);
	return (0);
}

char * reverseVowels(char * s){
	int		i;
	int 	j;
	char	temp;

	i = 0;
	j = strlen(s) - 1;
	while (i < j)
	{
		while (i < j && !isVowel(s[i]))
			i++;
		while (i < j && !isVowel(s[j]))
			j--;
		if (i < j)
		{
			temp = s[i];
			s[i++] = s[j];
			s[j--] = temp;
		}
	}
	return (s);
}

int main(void)
{
	char s[] = "LeetcOde";
	reverseVowels(s);
	printf("%s\n", s);
}