#include <stdio.h>
void findMinMaxDAC(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = arr[low];
        return;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    int min1, max1, min2, max2;
    findMinMaxDAC(arr, low, mid, &min1, &max1);
    findMinMaxDAC(arr, mid + 1, high, &min2, &max2);
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}
int main() {
    int arr[] = {5, 8, 1, 3, 9, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    findMinMaxDAC(arr, 0, n - 1, &min, &max);
    printf("Divide and Conquer:\nMinimum = %d, Maximum = %d\n", min, max);
    return 0;
}
