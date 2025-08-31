#include <stdio.h>
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bucketSort(float arr[], int n) {
    int bucketCount = n;
    float buckets[n][n];
    int bucketSizes[n];
    for (int i = 0; i < n; i++)
        bucketSizes[i] = 0;
    for (int i = 0; i < n; i++) {
        int bi = (int)(arr[i] * n);
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0)
            insertionSort(buckets[i], bucketSizes[i]);
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.25, 0.36, 0.58, 0.41, 0.29, 0.22, 0.45, 0.79, 0.01, 0.69};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
    return 0;
}
