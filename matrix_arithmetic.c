
#include"matrix_arithmetic.h"

void matrix_addition(int **matrix1, int **matrix2, int **result, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}


void matrix_subtraction(int **matrix1, int **matrix2, int **result, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrix_multiplication(int **matrix1, int **matrix2, int **result, int rowsmatrix1, int colsmatrix1, int rowsmatrix2, int colsmatrix2)
{
    if (colsmatrix1 != rowsmatrix2) 
    { 
        printf("Multiplication not possible: columns of matrix1 must equal rows of matrix2.\n"); 
        return; 
    }
    for(int i = 0; i < rowsmatrix1; i++)
    {
        for(int j = 0; j < colsmatrix2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsmatrix1; k++) 
            { 
                result[i][j] += matrix1[i][k] * matrix2[k][j]; 
            }
        }
    }
}

