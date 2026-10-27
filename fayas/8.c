#include <stdio.h>

int main()
{
    int sparse[20][3], transpose[20][3];
    int mat[10][10];
    int rows, cols, val = 0;
    int i, j, k = 1;

    // Input rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Input matrix
    printf("Enter the elements of the matrix:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);

            if (mat[i][j] != 0)
            {
                val++;
            }
        }
    }

    // First row of sparse matrix
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = val;

    // Store non-zero elements
    k = 1;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (mat[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    // Transpose header
    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = val;

    // Create transpose
    k = 1;

    for (j = 0; j < cols; j++)
    {
        for (i = 1; i <= val; i++)
        {
            if (sparse[i][1] == j)
            {
                transpose[k][0] = sparse[i][1];
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];
                k++;
            }
        }
    }

    // Display original sparse matrix
    printf("\nOriginal Sparse Matrix - Tuple Representation:\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= val; i++)
    {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    // Display transpose
    printf("\nTranspose - Tuple Representation:\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= val; i++)
    {
        printf("%d\t%d\t%d\n",
               transpose[i][0],
               transpose[i][1],
               transpose[i][2]);
    }

    return 0;
}

