#include <stdlib.h>
#include <stdio.h>

int timeRequiredToBuy(int* tickets, int ticketsSize, int k){
    int counter = 0;
    while (tickets[k] != 0)
    {
        for (int i = 0; i < ticketsSize && tickets[k] != 0; i++)
        {
            if (tickets[i] > 0)
            {
                tickets[i]--;
                counter++;
            }
        }
    }
    return (counter);
}

int main()
{
	int tickets[] = {84,49,5,24,70,77,87,8};
	int ticketsSize = sizeof(tickets) / sizeof(tickets[0]);
	int k = 3;
	int result = timeRequiredToBuy(tickets, ticketsSize, k);
	printf("%d", result);
	return (0);
}