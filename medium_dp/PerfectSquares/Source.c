
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *sqs;
int *sqcnt;
int sqscnt;

int dpsqcnt(int n) {
	int min, i, tcnt;

	if (n < 0) return INT_MAX;
	if (n == 0) return 0;
	if (sqcnt[n] != -1) return sqcnt[n];

	printf("%d ", n);

	min = INT_MAX;
	for (i = sqscnt; i >= 1; --i) {
		if ((n - sqs[i]) < 0) continue;
		tcnt = 1 + dpsqcnt(n - sqs[i]);
		if (tcnt < min) min = tcnt;
	}
	return (sqcnt[n]=min);
}

int dpsqcnt2(int n) {
	int min, i, tcnt;

	if (n < 0) return INT_MAX;
	if (n == 0) return 0;
	if (sqcnt[n] != -1) return sqcnt[n];

	min = INT_MAX;
	for (i = 1; i <= sqscnt; i++) {
		if ((n - sqs[i]) < 0) break;
		tcnt = 1 + dpsqcnt(n - sqs[i]);
		if (tcnt < min) min = tcnt;
	}
	return (sqcnt[n] = min);
}

int numSquares(int n) {
	int j, ret;

	sqscnt = sqrt(n);
	sqs = (int*)malloc((sqscnt+1)*sizeof(int));
	sqcnt = (int*)malloc((n+1)*sizeof(int));
	for (j = 0; j <= sqscnt; ++j) {
		sqs[j] = j*j;
	}
	for (j = 0; j <= n; j++) {
		sqcnt[j] = -1;
	}
	ret = dpsqcnt(n);
	free(sqs);
	free(sqcnt);
	return ret;
}

int numSquares2(int n) {

	int i;
	int ret;

	
	if (n <= 1) return 1;

	i = sqrt(n);
	ret = 1;
	if ((i*i) != n) {
		printf("%d ", i*i);
		ret += numSquares(n - (i*i));
	} else printf("%d ", i*i);
	return ret;
}


int main()
{
	int n;

	n = 12;
	printf("\n%d\n", numSquares(n));
}
