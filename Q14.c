// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>
int main()
{
    int n, i, j;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int isIdentity = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                isIdentity = 0;
                break;
            }
            if (i != j && matrix[i][j] != 0)
            {
                isIdentity = 0;
                break;
            }
        }
    }
    if (isIdentity == 1)
        printf("The matrix is an Identity Matrix.\n");
    else
        printf("The matrix is NOT an Identity Matrix.\n");
    return 0;
}
