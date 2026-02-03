//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include<stdio.h>
int main()
{
    int n;
    printf("enter no of elmeents: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int x;
    printf("enter element to be searched: ");
    scanf("%d",&x);
    int count=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        count++;
        if(arr[i]==x)
        {
            printf("found at index: %d\n",i);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("not found");
    }
    printf("Comparisons: %d",count);
    return 0;
}