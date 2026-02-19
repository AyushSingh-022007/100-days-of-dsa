//Problem: Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void closestToZero(int arr[], int n) {
    if (n < 2) {
        printf("Need at least two elements\n");
        return;
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = arr[left] + arr[right];
    int min_l = left, min_r = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_l = left;
            min_r = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Elements: %d and %d\n", arr[min_l], arr[min_r]);
    printf("Sum closest to zero: %d\n", min_sum);
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]);

    closestToZero(arr, n);

    return 0;
}
