#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *strToArray(char *a, int max_len)
{
	int	i;
	int	j;
	int	*array;

	array = (int *)malloc(sizeof(int) * (max_len));
	i = max_len - 1;
	j = strlen(a) - 1;
	while (j >= 0)
		array[i--] = a[j--] - '0';
	while (i >= 0)
		array[i--] = 0;
	return (array);
}

char	*getSum(int *A, int *B, int max_len)
{
	int 	i;
	int 	k;
	int		carry;
	int		*C;
	char 	*ans;

	C = (int *)malloc(sizeof(int) * max_len);
	i = max_len - 1;
	carry = 0;
	while (i >= 0)
	{
		C[i] = (A[i] + B[i] + carry) % 2;
		if (A[i] + B[i] + carry > 1)
			carry = 1;
		else
			carry = 0;
		i--;
	}
	if (carry == 1)
	{
		ans = (char *)malloc(sizeof(char) * (max_len + 2));
		k = 1;
		ans[0] = '1';
		for (i = 0; i < max_len; i++)
			ans[k++] = C[i] + '0';
		ans[k] = '\0';
		return (ans);
	}
	else
	{
		ans = (char *)malloc(sizeof(char) * (max_len + 1));
		for (i = 0; i < max_len; i++)
			ans[i] = C[i] + '0';
		ans[i] = '\0';

		return (ans);
	}
}

char	*addBinary(char *a, char *b)
{
	int		*A;
	int 	*B;

	int max_len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
	A = strToArray(a, max_len);
	B = strToArray(b , max_len);
	return (getSum(A, B, max_len));
}

int main(void)
{
	char *a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
	char *b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
	printf("%s\n", addBinary(a, b));
	return (0);
}
