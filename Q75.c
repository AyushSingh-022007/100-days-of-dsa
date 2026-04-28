#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int max_len = 0;

    // store prefix sum and its first index
    int sum[1000];
    int index[1000];
    int size = 0;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: sum = 0 from start
        if(prefix_sum == 0) {
            max_len = i + 1;
        }

        int found = 0;

        // check if prefix_sum seen before
        for(int j = 0; j < size; j++) {
            if(sum[j] == prefix_sum) {
                int len = i - index[j];
                if(len > max_len) {
                    max_len = len;
                }
                found = 1;
                break;
            }
        }

        // store first occurrence
        if(!found) {
            sum[size] = prefix_sum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", max_len);

    return 0;
}