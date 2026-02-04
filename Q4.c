//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include<stdio.h>
int main()
{
    int n;
    printf("enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("enter elememt: ");
        scanf("%d",&arr[i]);
    }
    int m=0,k=n-1;
    while(m<k)
    {
        int temp=arr[m];
        arr[m]=arr[k];
        arr[k]=temp;
        m++;
        k--;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}