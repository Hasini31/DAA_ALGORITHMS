#include <stdio.h>
void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int partitioning(int arr[], int low, int high) {
int p, i, j;
p = arr[low];
i = low + 1;
j = high;
while (i <= j) {
  while (i <= high & arr[i] <= p) {
  i++;
  }
  while (arr[j] > p) {
  j--;
  }
  if (i < j) {
  swap(&arr[i], &arr[j]);
 }
}
 swap(&arr[j], &arr[low]);
return j;
}

void Quicksort(int arr[], int low, int high) {
int p;
if (low < high) {
p = partitioning(arr, low, high);
  Quicksort(arr, low, p - 1);
  Quicksort(arr, p + 1, high);
 }
}

int main() {
  int arr[100], n, i;
printf("enter the n value:");
scanf("%d",&n);
printf("enter the values");
 for (i = 0; i < n; i++) {
  scanf("%d", &arr[i]);
 }
Quicksort(arr, 0, n - 1);
for (i = 0; i < n; i++) {
 printf("%d ", arr[i]);
}
    return 0;
}
