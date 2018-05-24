#include <stdio.h>
#include <stdlib.h>

struct NumArray {
	int *sum;
	int size;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	struct NumArray *p;
	int i;
	p = malloc(sizeof(struct NumArray));
	p->size = numsSize;
	p->sum = malloc(sizeof(int)*numsSize);
	p->sum[0] = nums[0];
	for (i = 1; i < numsSize; i++) {
		p->sum[i] = p->sum[i - 1] + nums[i];
	}
	return p;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	if(i==0) return numArray->sum[j];
	else return numArray->sum[j] - numArray->sum[i-1];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	free(numArray->sum);
	free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

int main()
{
	int nums[] = { -2, 0, 3, -5, 2, -1};
	const int numsSize = sizeof(nums)/sizeof(nums[0]);
	struct NumArray* numArray = NumArrayCreate(nums, numsSize);

	printf("sum[%d,%d]=%d\n", 0, 2, sumRange(numArray, 0, 2));
	printf("sum[%d,%d]=%d\n", 2, 5, sumRange(numArray, 2, 5));
	printf("sum[%d,%d]=%d\n", 0, 5, sumRange(numArray, 0, 5));
	NumArrayFree(numArray);

	return 0;
}

