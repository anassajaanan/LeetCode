#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
	int	i;
	int len_r;
	int len_m;
	int	HT[26];

	len_r = strlen(ransomNote);
	len_m = strlen(magazine);
	if (len_r > len_m)
		return (false);
	for (i = 0; i < 26; i++)
		HT[i] = 0;
	for (i = 0; ransomNote[i]; i++)
		HT[ransomNote[i] - 'a']++;
	for (i = 0; magazine[i]; i++)
		HT[magazine[i] - 'a']--;
	for (i = 0; i < 26; i++)
	{
		if (HT[i] > 0)
			return (false);
	}
	return (true);
}

int main(void)
{
	char	ransomNote[] = "aa";
	char	magazine[] = "ab";

	printf("%d\n", canConstruct(ransomNote, magazine));
	return (0);
}