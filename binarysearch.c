#include <stdio.h>

int binarySearch(int arr[], int left, int right, int s) {
while (left <= right) {
  int mid = left + (right - left) / 2;
  if (arr[mid] == s)
      return mid;
  else if (arr[mid] < s)
    left = mid + 1;
else
  right = mid - 1;
    }
    return -1;
}
int main(){
  int n,i,arr[100],s;
  printf("enter n:");
  scanf("%d",&n);
  printf("enter s value:");
  scanf("%d",&s);
 int result= binarySearch(arr,0,n-1,s);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  if(result>=0){
    printf("elements found at %d position ",i);
  }
  else{
    printf("element does not exists"); 
  }
}

  