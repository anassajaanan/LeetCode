#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool Isomorphic(char *s, char *t)
{
	int i;
	int j;
	int	HT[127];

	i = 0;
	for (i = 0; i < 127; i++)
		HT[i] = -200;
	i = 0;
	j = 0;
	while (s[i] && t[j])
	{
		if (HT[(int)s[i]] == -200)
			HT[(int)s[i]] = (int)(s[i] - t[j]);
		else
		{
			if (HT[(int)s[i]] != (int)(s[i] - t[j]))
				return (false);
		}
		i++;
		j++;
	}
	return (true);
}

bool isIsomorphic(char * s, char * t){
	return (Isomorphic(s , t) && Isomorphic(t, s));
}

int main(void)
{
	char s[] = "aba";
	char t[] = "baa";
	printf("%d\n", Isomorphic(t, s));
	return (0);
}