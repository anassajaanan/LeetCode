#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
	int i = 0;
	if (flowerbedSize == 1 && flowerbed[0] == 0)
		return (true);
	while (i < flowerbedSize && n > 0)
	{
		if (flowerbed[i] == 0)
		{
			if (i == 0 || i == flowerbedSize - 1)
			{
				if (i == 0 && flowerbed[i + 1] == 0)
				{
					flowerbed[i] = 1;
					n--;
				}
				else if (i == flowerbedSize - 1 && flowerbed[i - 1] == 0)
				{
					flowerbed[i] = 1;
					n--;
				}
			}
			else
			{
				if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
				{
					flowerbed[i] = 1;
					n--;
				}
			}
			i++;
		}
		else
			i += 2;
		
	}
	if (n > 0)
		return (false);
	return (true);
}

int main(void)
{
	int flowerbed[] = {0,1,0};
	int flowerbedSize = 3;
	int n = 1;
	printf("%d\n", canPlaceFlowers(flowerbed, flowerbedSize, n));
	return (0);
}