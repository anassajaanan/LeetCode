#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char	*removeBackspaces(char *s)
{
	int i = 0;
	int j = 0;
	int len_s = strlen(s);
	while (j < len_s)
	{
		if (s[j] == '#')
		{
			if (i > 0)
				i--;
			s[i] = '\0';
			j++;
		}
		else if (s[j] != '#' && s[j + 1] != '#')
		{
			s[i++] = s[j];
			j++;
		}
		else if (s[j] != '#' && s[j + 1] == '#')
			j += 2;
	}
	s[i] = '\0';
	return (s);
}

bool	backspaceCompare(char * s, char * t){
	return (strcmp(removeBackspaces(s), removeBackspaces(t)) == 0);
}

int main(void)
{
	char s[] = "ab##";
	char t[] = "a#c#";
	printf("%d\n", backspaceCompare(s, t));
	return (0);

}

