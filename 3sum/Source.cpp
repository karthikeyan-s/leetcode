
#include <stdio.h>
#include<malloc.h>


/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** threeSum(int* nums, int numsSize, int* returnSize) {

	int **ret = (int**)malloc(sizeof(int*) * (numsSize*(numsSize-1)*(numsSize-2) ));
	int i, j, k;
	const int target = 0;
	int retsize;

	retsize = 0;
	for (i = 0; i < numsSize; i++) {
		for (j = 0; (j < numsSize); j++) {
			if (i == j) continue;
			for(k=0;k<numsSize;k++) {
				if ((k == i) || (k == j)) continue;
				if (target == (nums[i] + nums[j] +nums[k])) {
					ret[retsize] = (int*)malloc(sizeof(int) * 3);
					ret[retsize][0] = i; // nums[i];
					ret[retsize][1] = j;// nums[j];
					ret[retsize][2] = k;// nums[k];
					retsize++;
				}
			}
		}
	}
	*returnSize = retsize;
	return ret;
}


int main() {

	int nums[] = { -1, 0, 1, 2, -1, -4 };
	int **sumnums;
	int sumcnt;
	int i;

	sumnums = threeSum(nums, sizeof(nums) / sizeof(nums[0]), &sumcnt);

	for (i = 0; i < sumcnt; i++) {
		printf("[%d, %d, %d]\n", sumnums[i][0], sumnums[i][1], sumnums[i][2]);
	}
	free(sumnums);

	return 0;
}

