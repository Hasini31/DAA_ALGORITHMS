#include <iostream>
#include <climits>
using namespace std;
int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
        }
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum)  rightSum = sum;
    }
    return leftSum + rightSum; }
int maxSubArray(int arr[], int low, int high) {
    if (low == high)
        return arr[low];
    int mid = (low + high) / 2;
    int leftMax = maxSubArray(arr, low, mid);
    int rightMax = maxSubArray(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);
    return max(max(leftMax, rightMax), crossMax);
}int main() {
    int arr[] = {2, -4, 3, -1, 2, -4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubArray(arr, 0, n - 1);
    cout << "Maximum Subarray Sum = " << maxSum << endl;
    return 0; }
