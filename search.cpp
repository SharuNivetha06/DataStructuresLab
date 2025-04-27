//C++ menu-driven program to search a target number in an array
#include<stdio.h>
#include"head.h"
#include<cstdlib>

//linear search
int linearsearch(int arr[],int n,int search)
{
    for(int i=0;i<n;i++){
    if(arr[i]==search)
    return i;
    }
 return -1;
}

//binary search
int binarysearch(int arr[],int n,int search)
{
    int low=0,high=n-1;
    while(low<=high){
       int middle=(low+high)/2;
        if(arr[middle]==search)
        return middle;
        else if(arr[middle]<search)
        low=middle+1;
        else if(arr[middle]>search)
        high=middle-1;
    }
    return -1;
}

//main function
int main(){
    int flag=0;
    int search;

//array input
printf("Enter array size\n");
int n;
scanf("%d",&n);
printf("Enter array of size %d\n",n);
int arr[n];
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}

//menu
    printf("1.Linear Search\n");
    printf("2.Binary Search\n");
    printf("3.Exit\n");

printf("Enter choice\n");
scanf("%d",&flag);

//choosing the sorting technique
switch(flag){
case 1:
{
  printf("Enter search element\n");
  scanf("%d",&search);
  printf("Linear Search \n");
  int ans=linearsearch(arr,n,search);
  if(ans!=-1)
  printf("\nSearch element found\n");
  else
  printf("\nSearch element not found\n");

printf("1.Linear Search\n");
printf("2.Binary Search\n");
printf("3.Exit\n");

printf("Enter choice\n");
scanf("%d",&flag);
break;

}
case 2:
{
  printf("Enter search element\n");
  scanf("%d",&search);
  printf("Binary Search \n");
  bubblesort(arr,n);
  int ans=binarysearch(arr,n,search);
  if(ans!=-1)
  printf("\nSearch element found\n ");
  else
  printf("\nSearch element not found\n");

printf("1.Linear Search\n");
printf("2.Binary Search\n");
printf("3.Exit\n");

printf("Enter choice\n");
scanf("%d",&flag);
break;

}
case 3:
{
    printf("\nCompleted");
    exit;
    
}
}
}