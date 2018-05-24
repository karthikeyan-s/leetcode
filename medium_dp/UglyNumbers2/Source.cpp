
#include <stdio.h>
#include<stdlib.h>

int min3(int a, int b, int c)
{
	if (a < b) {
		if (a < c) return a;
		else return c;
	}
	else {
		if (b < c) return b;
		else return c;
	}
}

int nthUglyNumber(int n) {

		int l1, l2, l3;
		int ucnt;
		int minl;
		int *u;

		u = (int*)malloc(sizeof(int)*n);

		l1 = l2 = l3 = 0;
		ucnt = 1;
		u[0] = 1;
		while (ucnt < n) {
			u[ucnt] = min3(u[l1] * 2, u[l2] * 3, u[l3] * 5);
			if (u[ucnt] == (u[l1] * 2)) l1++;
			if (u[ucnt] == (u[l2] * 3)) l2++;
			if (u[ucnt] == (u[l3] * 5)) l3++;
			ucnt++;
		}
		minl = u[n - 1];
		free(u);
		return minl;
}

int main()
{
	int u;

	u = nthUglyNumber(10);
	printf("%d\n", u);
	return 0;
}