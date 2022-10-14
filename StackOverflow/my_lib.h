#pragma once

// Our custom 2D matrix struct
typedef struct Matrix {
	int rows; // number of rows
	int cols; // number of columns
	double** data; // a pointer to an array of n_rows pointers to rows
}Matrix;

Matrix* make_matrix(int n_rows, int n_cols);
void print_matrix(Matrix* m);
