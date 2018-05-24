#include <stdio.h>
#include <stdlib.h>

struct NumMatrix {
	int *integral;
	int width, height;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {

	struct NumMatrix* mat;
	int i, j;
	int *p1, *p2;

	mat = (struct NumMatrix*)malloc(sizeof(struct NumMatrix));
	mat->integral = (int*)malloc(matrixRowSize*matrixColSize*sizeof(int));
	mat->width = matrixColSize;
	mat->height = matrixRowSize;

	mat->integral[0] = matrix[0][0];
	for (i = 1; i < mat->width; i++) {
		mat->integral[i] = matrix[0][i] + mat->integral[i - 1];
	}
	p1 = mat->integral;
	p2 = p1 + mat->width;
	for (i = 1; i < mat->height; i++) {
		*p2 = matrix[i][0] + *p1;
		p1 = p2;
		p2 += mat->width;
	}
	p1 = &mat->integral[1];
	p2 = p1 + mat->width;
	for (i = 1; i < mat->height; i++) {
		for (j = 1; j < mat->width; j++) {
			*p2 = matrix[i][j] + p2[-1] + p1[0] - p1[-1];
			p1++;
			p2++;
		}
		p1++;
		p2++;
	}
	return mat;
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {
	int a, b, c, d;
	a = b = c = d = 0;
	if (row1 > 0) {
		b = numMatrix->integral[(row1 - 1) * numMatrix->width + col2];
		if (col1 > 0) {
			a = numMatrix->integral[(row1 - 1) * numMatrix->width + col1-1];
		}
	}
	if (col1 > 0) {
		c = numMatrix->integral[row2 * numMatrix->width + col1 - 1];
	}
	d = numMatrix->integral[row2 * numMatrix->width + col2];
	return (d + a - b - c);
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) {

	free(numMatrix->integral);
	free(numMatrix);
}

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);

int main()
{
	int mat[][2] = {
		{-4, -5},
	};
	int *matrix[2];
	matrix[0] = mat[0];
	matrix[1] = mat[1];
	struct NumMatrix* numMatrix = NumMatrixCreate(matrix, 1, 2);

	printf("%d:\n", sumRegion(numMatrix, 0, 0, 0, 0));
	printf("%d:\n", sumRegion(numMatrix, 0, 0, 0, 1));
	printf("%d:\n", sumRegion(numMatrix, 0, 1, 0, 1));
	NumMatrixFree(numMatrix);

	return 0;
}

int main1()
{
	int mat[][5] = {
		{ 3, 0, 1, 4, 2 },
		{ 5, 6, 3, 2, 1 },
		{ 1, 2, 0, 1, 5 },
		{ 4, 1, 0, 1, 7 },
		{ 1, 0, 3, 0, 5 }
	};
	int *matrix[5];
	matrix[0] = mat[0];
	matrix[1] = mat[1];
	matrix[2] = mat[2];
	matrix[3] = mat[3];
	matrix[4] = mat[4];
	struct NumMatrix* numMatrix = NumMatrixCreate(matrix, 5, 5);

	printf("%d:\n", sumRegion(numMatrix, 2, 1, 4, 3));
	printf("%d:\n", sumRegion(numMatrix, 1, 1, 2, 2));
	printf("%d:\n", sumRegion(numMatrix, 1, 2, 2, 4));
	NumMatrixFree(numMatrix);

	return 0;
}