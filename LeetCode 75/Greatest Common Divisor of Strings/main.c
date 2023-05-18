#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	getGDC(char *str, int f, int l)
{
	int i, j;
	i = 0;
	j = 1;
	while (j < l && str[i] != str[j])
		j++;
	
}

void	gcdOfStrings(char * str1, char * str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 % len2 != 0)
		return (strdup(""));
	for (int i = 0, j = 0; i < len1 && j < len2; i++, j++)
	{
		if (str1[i] != str2[j])
			return (strdup(""));
	}

}

int main(void)
{
	char str1[] = "ABABABC";

	getRepeated(str1, 0, strlen(str1));

	// char str2[] = "ABC";
	// gcdOfStrings(str1, str2);
	// printf("%s\n", gcdOfStrings(str1, str2));
	// return (0);
}