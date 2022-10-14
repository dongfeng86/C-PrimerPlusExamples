#include "my_lib.h"
#include <stdio.h>

// CREATE A MATRIX WITH N_ROWS AND N_COLUMNS AND INITIALIZE EACH VALUE AS 0
Matrix* make_matrix(int n_rows, int n_cols) {
	Matrix* matrix = malloc(sizeof(Matrix));
	matrix->rows = n_rows;
	matrix->cols = n_cols;
	double** data = malloc(sizeof(double*) * n_rows);
	for (int x = 0; x < n_rows; x++) {
		data[x] = calloc(n_cols, sizeof(double));
	}
	matrix->data = data;
	return matrix;
}

// PRINT GIVEN MATRIX TO COMMAND LINE
void print_matrix(Matrix* m) {
	for (int x = 0; x < m->rows; x++) {
		for (int y = 0; y < m->cols; y++) {
			printf("%f", m->data[x][y]);
			printf("|");
		}
		printf("\n");
	}
}

