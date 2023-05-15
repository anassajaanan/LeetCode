#include <stdio.h>
#include <stdlib.h>

int getMaxIndex(int *prices, int f, int l)
{
	int max;
	int maxIndex;

	max = -2147483647;
	for (int i = f; i <= l; i++)
	{
		if (prices[i] > max)
		{
			max = prices[i];
			maxIndex = i;
		}
	}
	return (maxIndex);
}

int getMinIndex(int *prices, int f, int l)
{
	int min;
	int minIndex;

	min = 2147483647;
	for (int i = f; i <= l; i++)
	{
		if (prices[i] < min)
		{
			min = prices[i];
			minIndex = i;
		}
	}
	return (minIndex);
}


int	maxProfit(int* prices, int pricesSize)
{
	int is_deceanding;
	int maxIndex;
	int minIndex;

	is_deceanding = 1;
	for (int i = 0; i < pricesSize - 1; i++)
	{
		if (prices[i + 1] > prices[i])
		{
			is_deceanding = 0;
			break;
		}
	}
	if (is_deceanding)
		return (0);
	maxIndex = getMaxIndex(prices, 0, pricesSize - 1);
	minIndex = getMinIndex(prices, 0, pricesSize - 1);
	while (maxIndex < minIndex && maxIndex == 0 && minIndex == pricesSize - 1)
	{
		maxIndex = getMaxIndex(prices, maxIndex + 1, pricesSize - 1);
		minIndex = getMinIndex(prices, 0, minIndex - 1);

	}
	if (maxIndex < minIndex)
	{
		int maxIndex1 = getMaxIndex(prices, minIndex + 1, pricesSize - 1);
		int minIndex1 = getMinIndex(prices, 0, maxIndex - 1);
		if (prices[maxIndex1] - prices[minIndex] > prices[maxIndex] - prices[minIndex1])
			return (prices[maxIndex1] - prices[minIndex]);
		else
			return (prices[maxIndex] - prices[minIndex1]);
	}
	int ans = prices[maxIndex] - prices[minIndex];
	return (ans);
}

int main(void)
{
	int prices[] = {7,2, 4, 1};
	int pricesSize = 4;
	printf("%d\n", maxProfit(prices, pricesSize));
	return (0);
}
