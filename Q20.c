//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int countZeroSumSubarrays(int arr[], int n) {

    int count = 0;
    int prefixSum = 0;
    int offset = MAX;
    int hash[2 * MAX + 1] = {0};

    for (int i = 0; i < n; i++) {

        prefixSum += arr[i];

        if (prefixSum == 0)
            count++;

        if (hash[prefixSum + offset] > 0)
            count += hash[prefixSum + offset];

        hash[prefixSum + offset]++;
    }

    return count;
}

int main() {

    int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Number of zero-sum subarrays: %d",
           countZeroSumSubarrays(arr, n));

    return 0;
}