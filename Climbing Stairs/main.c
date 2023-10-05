#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int array[45] = {0};

int climbStairs(int n){
	if (n == 0 || n == 1)
	{
		return (1);
	}
	if (array[n] != 0)
		return (array[n]);
	array[n - 1] = climbStairs(n - 1);
	array[n - 2] = climbStairs(n - 2);
	return (array[n - 1] + array[n - 2]);
}

int climbStairs(int n){
	if (n == 0 || n == 1)
		return (1);
	return (climbStairs(n - 1) + climbStairs(n - 2));
}

int main(void)
{
	printf("%d\n", climbStairs(45));
}