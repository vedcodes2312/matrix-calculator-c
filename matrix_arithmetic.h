#ifndef MATRIX_ARITHMETIC_H
#define MATRIX_ARITHMETIC_H

#include<stdio.h>
#include<stdlib.h>

void matrix_addition(int **matrix1, int **matrix2, int **result, int rows, int cols);
void matrix_subtraction(int **matrix1, int **matrix2, int **result, int rows, int cols);
void matrix_multiplication(int **matrix1, int **matrix2, int **result, int rowsmatrix1, int colsmatrix1, int rowsmatrix2, int colsmatrix2);

#endif