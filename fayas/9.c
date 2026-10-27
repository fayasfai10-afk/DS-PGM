#include <stdio.h>

int main()
{
    int a[20][3], b[20][3], c[40][3];
    int rows, cols;
    int i, j, k;

    // Read rows and columns only once
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // ---------------- MATRIX A ----------------

    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = 0;

    k = 1;

    printf("\nEnter values of Matrix A:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            int value;

            printf("A[%d][%d] = ", i, j);
            scanf("%d", &value);

            if (value != 0)
            {
                a[k][0] = i;
                a[k][1] = j;
                a[k][2] = value;

                k++;
                a[0][2]++;
            }
        }
    }

    // ---------------- MATRIX B ----------------

    b[0][0] = rows;
    b[0][1] = cols;
    b[0][2] = 0;

    k = 1;

    printf("\nEnter values of Matrix B:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            int value;

            printf("B[%d][%d] = ", i, j);
            scanf("%d", &value);

            if (value != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = value;

                k++;
                b[0][2]++;
            }
        }
    }

    // ---------------- ADDITION ----------------

    c[0][0] = rows;
    c[0][1] = cols;
    c[0][2] = 0;

    k = 1;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            int valueA = 0;
            int valueB = 0;
            int x;

            // Find value of A at [i][j]
            for (x = 1; x <= a[0][2]; x++)
            {
                if (a[x][0] == i && a[x][1] == j)
                {
                    valueA = a[x][2];
                    break;
                }
            }

            // Find value of B at [i][j]
            for (x = 1; x <= b[0][2]; x++)
            {
                if (b[x][0] == i && b[x][1] == j)
                {
                    valueB = b[x][2];
                    break;
                }
            }

            // Store only non-zero sum
            if (valueA + valueB != 0)
            {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = valueA + valueB;

                k++;
                c[0][2]++;
            }
        }
    }

    // ---------------- DISPLAY A ----------------

    printf("\nMatrix A - Tuple Representation:\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= a[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               a[i][0],
               a[i][1],
               a[i][2]);
    }

    // ---------------- DISPLAY B ----------------

    printf("\nMatrix B - Tuple Representation:\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= b[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               b[i][0],
               b[i][1],
               b[i][2]);
    }

    // ---------------- DISPLAY SUM ----------------

    printf("\nSum of Sparse Matrices:\n");
    printf("Row\tColumn\tValue\n");

    for (i = 0; i <= c[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               c[i][0],
               c[i][1],
               c[i][2]);
    }

    return 0;
}

