//Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include <stdio.h>
int main() {
    int i, j, rows, cols, sum = 0;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int n = (rows < cols) ? rows : cols;

    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    printf("Sum of primary diagonal elements = %d\n", sum);
    return 0;
}
