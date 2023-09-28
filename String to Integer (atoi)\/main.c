#include <stdio.h>
#include <limits.h>


int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		int digit = str[i] - '0';
		if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && digit > LONG_MAX % 10))
		{
			if (sign == 1)
				return (INT_MAX);
			else if (sign == -1 && (digit > 8))
				return (INT_MIN);
		}
		num = (num * 10) + digit;
		i++;
	}
	if (num > INT_MAX || num < INT_MIN)
		return (sign == 1 ? INT_MAX : INT_MIN);
	return (num * sign);
}


int main(void)
{
	char *str = "20000000000000000000";
	printf("{%d}\n", ft_atoi(str));
	return (0);
}



// if (sign == -1 && num * 10 < num)
		// 	return (-2147483648);
		// else if (sign == 1 && num * 10 < num)
		// 	return (2147483647);
		// if (sign == -1 && (num < INT_MIN / 10 || (num == INT_MIN / 10 && (str[i] - '0') > 8)))
        
        // else if (sign == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > 7)))
        // {
		// 	printf("yes\n");
		// 	return INT_MAX;
		// }