#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int maxProfit(int* prices, int pricesSize) 
{
	int *profit;
	int i, min;

	if (pricesSize == 0) return 0;

	profit = (int*)malloc(sizeof(int)*(pricesSize+1));

	profit[0] = 0;

	min = prices[0];
	for (i = 1; i < pricesSize; i++) {
		if (prices[i] < min)  min = prices[i];
		profit[i] = max(profit[i - 1], prices[i] - min);
	}

	return profit[pricesSize - 1];
}

int main()
{
	return 0;
}