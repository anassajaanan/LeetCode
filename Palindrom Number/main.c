#include <stdio.h>
#include <stdbool.h>

void	fill_array(int x, int *array, int *index)
{
	if (x > 0)
	{
		fill_array(x / 10, array, index);
		array[(*index)++] = x % 10;
	}
}


bool isPalindrome(int x)
{
	int array[11];
	int i = 0;
	int index = 0;

	if (x < 0)
		return (0);
	fill_array(x, array, &index);
	while (i < index)
	{
		if (x % 10 != array[i])
			return (0);
		i++;
		x = x / 10;
	}
	return (1);
}
