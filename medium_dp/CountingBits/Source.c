#include <stdio.h>
#include <stdlib.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* countBits(int num, int* returnSize) {
	int *count;
	int i, j;

	*returnSize = num + 1;
	count = (int*)malloc(sizeof(int)*(*returnSize));

	count[0] = 0;
	count[1] = 1;
	i = 2;
	while (i <= num) {
		for (j = 0; (j < i) && ( (i+j)<=num); j++) {
			count[i + j] = 1 + count[j];
		}
		i = i + j;
	}

	return count;
}


int main()
{
	int *p, rets;
	int i;

	p = countBits(5, &rets);
	for (i = 0; i < rets; i++) {
		printf("%d ", p[i]);
	}
	free(p);
	return 0;
}

