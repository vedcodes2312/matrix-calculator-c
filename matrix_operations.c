#include"matrix_operations.h"

int trace_matrix(int **matrix, int size)
{
    int trace = 0;
    for (int i = 0; i < size; i++)
    {
        trace += matrix[i][i];
    }
    return trace;
}

void transpose_matrix(int **matrix, int **transpose, int rows,int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    
}

int matrix_determinant(int **matrix, int size) 
{ 
    if (size == 1) 
    { 
        return matrix[0][0]; 
    }
int determinant = 0; 
int **submatrix = (int **)malloc((size - 1) * sizeof(int *));
for (int i = 0; i < size - 1; i++) 
{ 
    submatrix[i] = (int *)malloc((size - 1) * sizeof(int));
}
for (int x = 0; x < size; x++) 
{ 
    int subi = 0; 
for (int i = 1; i < size; i++) 
{ 
int subj = 0; 
for (int j = 0; j < size; j++) 
{
    if (j == x) 
    { 
        continue; 
    } 
        submatrix[subi][subj] = matrix[i][j];
         subj++; 
}
subi++; 
} 
determinant += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * matrix_determinant(submatrix, size - 1); 
} 
for (int i = 0; i < size - 1; i++) 
{ 
    free(submatrix[i]); 
} 
free(submatrix);
 return determinant; 
}

void get_cofactor(int **matrix, int **temp, int p, int q, int size) 
{
    int i = 0, j = 0;
    for (int row = 0; row < size; row++) 
    {
        for (int col = 0; col < size; col++) 
        {
            if (row != p && col != q) 
            {
                temp[i][j++] = matrix[row][col];
                if (j == size - 1) 
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void adjoint_matrix(int **matrix, int **adjoint, int size) 
{
    if (size == 1) 
    {
        adjoint[0][0] = 1;
        return ;
    }
    int sign = 1;
    int **temp = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) 
    {
        temp[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) 
        {
            get_cofactor(matrix, temp, i, j, size);
            sign = ((i + j) % 2 == 0) ? 1 : -1;  //ternary operator
            adjoint[j][i] = (sign) * (matrix_determinant(temp, size - 1));
        }
    }
    for (int i = 0; i < size; i++) 
    {
        free(temp[i]);
    }
    free(temp);
}

int matrix_inverse(int **matrix, int **inverse, int size) 
{
    int det = matrix_determinant(matrix, size);
    if (det == 0) 
    {
        printf("Matrix is singular and cannot have an inverse.\n");
        return 0;
    }
    int **adjoint = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) 
    {
        adjoint[i] = (int *)malloc(size * sizeof(int));
    }
    adjoint_matrix(matrix, adjoint, size);
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            inverse[i][j] = adjoint[i][j] / det;
        }
    }
    for (int i = 0; i < size; i++) 
    {
        free(adjoint[i]);
    }
    free(adjoint);
    return 1;
}


/*            MIT License

Copyright (c) 2024 Ved Vyas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.      */
