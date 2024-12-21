#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include<stdio.h>
#include<stdlib.h>

int trace_matrix(int **matrix, int size);
void transpose_matrix(int **matrix, int **transpose, int rows,int cols);
int matrix_determinant(int **matrix, int size);
int matrix_adjoint(int **matrix,int **result, int size);
int matrix_inverse(int **matrix, int **inverse, int size);

#endif


