#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void	reverseStr(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

char * addStrings(char * num1, char * num2){
	int i = 0, carry = 0, index = 0;
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int max_len = len1 > len2 ? len1 : len2;
	int min_len = len1 < len2 ? len1 : len2;
	char	*ans = (char *)malloc(sizeof(char) * (max_len + 2));
	reverseStr(num1);
	reverseStr(num2);
	while (i < min_len)
	{
		int sum = num1[i] - '0' + num2[i] - '0' + carry;
		ans[index++] = (sum % 10) + '0';
		carry = sum / 10;
		i++;
	}
	while (i < len1)
	{
		int sum = num1[i] - '0' + carry;
		ans[index++] = (sum % 10) + '0';
		carry = sum / 10;
		i++;
	}
	while (i < len2)
	{
		int sum = num2[i] - '0' + carry;
		ans[index++] = (sum % 10) + '0';
		carry = sum / 10;
		i++;
	}
	if (carry)
		ans[index++] = carry + '0';
	ans[index] = '\0';
	reverseStr(ans);
	return (ans);
}

int main(void)
{
	char num1[] = "6";
	char num2[] = "501";
	char *ans = addStrings(num1, num2);
	printf("%s\n", ans);
	return (0);
}