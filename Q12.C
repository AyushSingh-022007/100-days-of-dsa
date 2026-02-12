// Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
#include <stdio.h>
int main()
{
    int a[50][50], n, m, i, j, flag = 1;
    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);
    if (n != m)
    {
        printf("Matrix is not symmetric (not a square matrix).\n");
        return 0;
    }
    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != a[j][i])
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1)
        printf("Matrix is symmetric.\n");
    else
        printf("Matrix is not symmetric.\n");
    return 0;
}
