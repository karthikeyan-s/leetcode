
#include <stdio.h>
#include<malloc.h>


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target) {

	int *ret = (int*)malloc(sizeof(int) * 2);
	int i,j;

	for (i = 0; i < numsSize; i++) {
		for (j = 0; (j < numsSize); j++) {
			if (i == j) continue;
			if (nums[i] + nums[j] == target) {
				ret[0] = nums[i];
				ret[1] = nums[j];
				return ret;
			}
		}
	}
	return ret;
}


int main() {

	int nums[] = { 2, 7, 11, 15 };
	int target = 9;
	int *sumnums;

	sumnums = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target);

	printf("%d = %d + %d\n", target, sumnums[0], sumnums[1]);
	free(sumnums);

	return 0;
}