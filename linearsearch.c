#include<stdio.h>
int linearsearch(int arr[],int s,int n){
  int i;
  for(i=0;i<n;i++){
    if(arr[i]==s){
      break;
    }
  }
  if(i<n){
    return(1);
   }
  else{
    return 0;
   }
  }

int main(){
  int i,n,arr[100],s;
  printf("enter size:");
  scanf("%d",&n);
  printf("enter element that u want to search:");
  scanf("%d",&s);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  if(i=linearsearch(arr,s,n)){
    printf("element is exist at %d",i+1);
  }
  else{
    printf("element is not present");
  }
  return 0;
}