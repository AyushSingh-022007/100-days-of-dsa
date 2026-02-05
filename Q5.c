#include <stdio.h>
int main()
{
    int n1, n2;
    printf("enter no of elements for array 1: ");
    scanf("%d", &n1);
    printf("enter no of elements for array 2: ");
    scanf("%d", &n2);
    int a[n1];
    int b[n2];
    int c[n1 + n2];
    for(int i=0;i<n1;i++)
    {
        printf("enter elements for 1st array: ");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n2;i++)
    {
        printf("enter elements for 2st array: ");
        scanf("%d",&b[i]);
    }    
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        c[k++] = a[i];
    }
    for (int i = 0; i < n2; i++)
    {
        c[k++] = b[i];
    }
    for (int i = 0; i < n1 + n2 - 1; i++)
    {
        for (int j = 0; j < n1 + n2 - i - 1; j++)
        {
            if (c[j] > c[j + 1])
            {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}
