#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize) {
	int i, j;
	int cnt;
	int maxcnt;
	int n;

	maxcnt = 0;
	for (i = 0; i < numsSize; i++) {
		cnt = 1;
		n = nums[i];
		for (j = i + 1; j < numsSize; j++) {
			if (nums[j] > n) {
				n = nums[j];
				cnt++;
			}
		}
		if (cnt > maxcnt) maxcnt = cnt;
	}
	return maxcnt;
}

int main()
{

	int nums[] = { 10, 9, 2, 5, 3, 4 };// { 10, 9, 2, 5, 3, 7, 101, 18 };
	
	int ret;

	ret = lengthOfLIS(nums, sizeof(nums) / sizeof(nums[0]));

	printf("%d\n", ret);

	return 0;
}