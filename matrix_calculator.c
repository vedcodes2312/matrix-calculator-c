//matrix calculator

#include"matrix_arithmetic.h"
#include"matrix_operations.h"

void print_matrix(int **matrix,int rows,int cols)
{
    for(int i=0; i<rows; i++)
    {
       for(int j=0; j<cols; j++)

       {
        printf("%d ",matrix[i][j]);
       } 
       printf("\n");
    }
}
int main()
{
    //choose the operation to perform
    int rows, cols, size, choice, rows1, cols1, rows2, cols2;
    printf("Choose an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Trace\n");
    printf("5. Transpose\n");
    printf("6. Determinant\n");
    printf("7. Adjoint\n");
    printf("8. Inverse\n");
    printf("9. Exit\n");
    scanf("%d", &choice);
    if(choice >9 || choice < 1)
    {
        
        printf("Invalid choice please try again\n");
    }

    //certain conditions
    if(choice == 3)
    {
        printf("Enter the number of rows and columns of the first matrix:\n"); 
        scanf("%d %d", &rows1, &cols1); 
        printf("Enter the number of rows and columns of the second matrix:\n"); 
        scanf("%d %d", &rows2, &cols2);
    }

    else
    {
        printf("Enter the number of rows and columns of the matrices:\n"); 
        scanf("%d %d", &rows, &cols);
    }

    //dynamic memory allocations-malloc and double pointers
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    int **matrix3 = (int **)malloc(rows * sizeof(int *));
    int **matrix4 = (int **)malloc(rows * sizeof(int *));
    int **matrix = (int **)malloc(rows * sizeof(int *));
    int **result1 = (int **)malloc(rows1 * sizeof(int *));
    int **result2 = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows1; i++) 
    {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }
    for (int i = 0; i < rows2; i++) 
    {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }
    for (int i = 0; i < rows1; i++)
    {
        result1[i] = (int *)malloc(cols2 * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        matrix3[i] = (int *)malloc(cols * sizeof(int));
        matrix4[i] = (int *)malloc(cols * sizeof(int));
        matrix[i] = (int *)malloc(cols * sizeof(int));
        result2[i] = (int *)malloc(cols * sizeof(int));
    }  

    //input the elements
    if(choice == 3) 
  {
    
        printf("Enter the elements of the first matrix:\n");
        for (int i = 0; i < rows1; i++) 
        {
            for (int j = 0; j < cols1; j++) 
            {
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("Enter the elements of the second matrix:\n");
        for (int i = 0; i < rows2; i++) 
        {
            for (int j = 0; j < cols2; j++) 
            {
                scanf("%d", &matrix2[i][j]);
            }
        }
    } 
     else if(choice == 1 || choice == 2)
     {
        printf("Enter the elements of the first matrix:\n");
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                scanf("%d", &matrix3[i][j]);
            }
        }
         printf("Enter the elements of the second matrix:\n");
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                scanf("%d", &matrix4[i][j]);
            }
        }
     }
     else
     {
      printf("Enter the elements of the  matrix:\n");
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
     }

//switch case to perform operations

switch(choice) 
{
    case 1:
    matrix_addition(matrix3, matrix4, result2, rows, cols);
    printf("First matrix:\n");
    print_matrix(matrix3, rows, cols);
    printf("Second matrix:\n");
    print_matrix(matrix4, rows, cols);
    printf("Resultant Matrix after Addition:\n");
    print_matrix(result2, rows, cols);
    break;

   case 2:
   matrix_subtraction(matrix3, matrix4, result2, rows, cols);
   printf("First matrix:\n");
    print_matrix(matrix3, rows, cols);
    printf("Second matrix:\n");
    print_matrix(matrix4, rows, cols);
   printf("Resultant Matrix after Addition:\n");
   print_matrix(result2, rows, cols);
   break;

   case 3:
   matrix_multiplication(matrix1, matrix2, result1, rows1 , cols1, rows2, cols2);
   printf("First matrix:\n");
   print_matrix(matrix1, rows1, cols1);
   printf("Second matrix:\n");
   print_matrix(matrix2, rows2, cols2);
   printf("Resultant Matrix after Multiplication:\n");
   print_matrix(result1, rows1, cols2);
   break;

    case 4:
       if (rows == cols) 
        {
           printf("Entered matrix is a square matrix.\n");
           size = rows;
           printf("Entered Matrix: \n");
           print_matrix(matrix, rows, cols);
           int trace = trace_matrix(matrix, size);
           printf("Trace of the Matrix: %d\n", trace);
        } 
            else 
            {
                printf("Trace not possible: Matrix must be square.\n");
            }
        break;

   case 5:
   transpose_matrix(matrix, result2, rows, cols);
   printf("Original Matrix:\n");
   print_matrix(matrix, rows, cols);
   printf("Transpose of the Matrix:\n");
   print_matrix(result2, cols, rows);
  break; 
  
  case 6:
        if (rows == cols) 
        {
           printf("Entered matrix is a square matrix.\n");
           size = rows;
           printf("Entered Matrix: \n");
           print_matrix(matrix, rows, cols);
           int det = matrix_determinant(matrix, size);
           printf("Determinant of the Matrix: %d\n", det);
        } 
            else 
            {
                printf("Determinant not possible: Matrix must be square.\n");
            }
        break;  

case 7:
            if (rows == cols) 
            {
                printf("Entered matrix is a square matrix.\n");
               size = rows;
               printf("Entered Matrix: \n");
               print_matrix(matrix, rows, cols);
                adjoint_matrix(matrix, result2, size);
                printf("Adjoint of the Matrix:\n");
                print_matrix(result2, rows, cols);
            } 
            else 
            {
                printf("Adjoint not possible: Matrix must be square.\n");
            }
            break;

  case 8:
            if (rows == cols) 
            {
                printf("Entered matrix is a square matrix.\n");
               size = rows;
               printf("Entered Matrix: \n");
               print_matrix(matrix, rows, cols);
                matrix_inverse(matrix, result2, size);
                printf("Inverse of the Matrix:\n");
                print_matrix(result2, rows, cols);
            } 
            else 
            {
                printf("Inverse not possible: Matrix must be square.\n");
            }
            break;

   default:
   printf("Invalid choice.\n");
   break;
}     

//free allocated memory
for (int i = 0; i < rows1; i++) 
{
        free(matrix1[i]);
        free(result1[i]);
}
    for (int i = 0; i < rows2; i++) 
    {
        free(matrix2[i]);
    }

  for (int i = 0; i < rows; i++) 
    {
        free(matrix3[i]);
        free(matrix4[i]);
        free(matrix[i]);
        free(result2[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result1);
    free(matrix3);
    free(matrix4);
    free(matrix);
    free(result2);

  return 0;     //end of code
}


    


