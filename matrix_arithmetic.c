
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



/* MIT License

Copyright (c) 2024 Ved Vyas

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
    OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
    OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.    */
