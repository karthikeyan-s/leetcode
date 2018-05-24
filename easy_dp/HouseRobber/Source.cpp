#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int rob(int* nums, int numsSize) {
	int* dp;
	int i;
	dp = (int*)malloc(sizeof(int)*(numsSize+1));

	dp[0] = 0;
	dp[1] = nums[0];
	for (i = 2; i <= numsSize; i++) {
		dp[i] = max((nums[i - 1] + dp[i - 2]), dp[i - 1]);
	}
	i = dp[numsSize];
	free(dp);
	return i;
}

int main()
{
	int nums[] = { 1,3,2,2, 1 };

	printf("%d\n", rob(nums, sizeof(nums)/sizeof(nums[0])));
	return 0;
}

