#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	setlocale(LC_ALL, ".1251");

	printf("¬ведите размеры массива: ");
	int L, C;
	scanf("%d%d", &L, &C);

	int** matrix;
	matrix = new int* [L];
	for (int i = 0; i < L; i++)
		matrix[i] = new int[C];

	srand((unsigned)time(0));
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			matrix[i][j] = rand() ;
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	int sum = 0;
	for (int i = 0; i < L; i++) {
		if (i == 0 || i == L - 1) {
			for (int j = 0; j < C; j++) {
				sum += matrix[i][j];
			}
		}
		else {
			sum += matrix[i][0] + matrix[i][C - 1];
		}
	}
	printf("—умма границ: %d", sum);

	for (int i = 0; i < L; i++)
		delete matrix[L];
	delete matrix;

}