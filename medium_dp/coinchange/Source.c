#include <stdio.h>
#include <stdlib.h>

int minof(int a, int b) {
	return (a < b) ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) 
{
	int *dp;
	int i, mincnt;
	int j, cnt, ret;

	dp = (int*)malloc(sizeof(int)*(amount + 1));
	dp[0] = 0;
	for (i = 1; i <= amount; i++)
	{
		dp[i] = INT_MAX-1;
		for (j = 0; j < coinsSize; j++) {
			if ((i - coins[j]) >= 0) {
				cnt = 1 + dp[(i - coins[j])];
				dp[i] = minof(cnt, dp[i]);
			}
		}
	}
	ret = (dp[amount] == INT_MAX-1)?-1:dp[amount];
	free(dp);
	return ret;
}


int main()
{
	int coins[] = {1,2,5};

	printf("%d\n", coinChange(coins, sizeof(coins) / sizeof(coins[0]), 11));
	
	return 0;
}