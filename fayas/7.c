#include <stdio.h>

int main()
{
    int mat[10][10];
    int tup[10][3];
    int row, col, i, j, k = 1, nonzero = 0;

    printf("Enter the row: ");
    scanf("%d", &row);

    printf("Enter the column: ");
    scanf("%d", &col);

    printf("Enter the elements:\n");

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);

            if (mat[i][j] != 0)
            {
                nonzero++;
            }
        }
    }

    // First row contains rows, columns and number of non-zero elements
    tup[0][0] = row;
    tup[0][1] = col;
    tup[0][2] = nonzero;

    // Store non-zero elements
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (mat[i][j] != 0)
            {
                tup[k][0] = i;
                tup[k][1] = j;
                tup[k][2] = mat[i][j];
                k++;
            }
        }
    }

    // Display tuple representation
    printf("\nTuple Representation:\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= nonzero; i++)
    {
        printf("%d\t%d\t%d\n",
               tup[i][0],
               tup[i][1],
               tup[i][2]);
    }

    return 0;
}

