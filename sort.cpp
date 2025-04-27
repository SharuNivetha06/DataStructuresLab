//C++ menu-driven program to sort a given array in ascending order
#include<stdio.h>
#include<cstdlib>

// bubblesort
void bubblesort(int arr[],int n)
{
 {
  for(int i=0;i<n-1;i++){
     for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
          int temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
    }
}
}
}
for(int i=0;i<n;i++){
  printf("%d\t",arr[i]);
}
}

//selectionsort
void selectionsort(int arr[],int n){{
for(int i=0;i<n-1;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
     int temp=arr[min];
     arr[min]=arr[i];
     arr[i]=temp;
            
        
    }
}
for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
}
}

//insertion sort 
void insertionsort(int arr[],int n){
{
    int key,j;
for(int i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        --j;
    }
    arr[j+1]=key;
}
}
for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
}
}

//main function
int main()
{
  int flag=0;

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
    printf("1.Bubble sort\n");
    printf("2.Selection sort\n");
    printf("3.Insertion sort\n");
    printf("4.Exit\n");

printf("Enter choice\n");
scanf("%d",&flag);

//choosing the sorting technique
switch(flag){
case 1:
{
  printf("Bubble sort \n");
  bubblesort(arr,n);
  printf("1.Bubble sort\n");
  printf("2.Selection sort\n");
  printf("3.Insertion sort\n");
  printf("4.Exit\n");

  printf("Enter choice\n");
  scanf("%d",&flag);
  break;

}
case 2:
{
  printf("Selection sort \n");
  selectionsort(arr,n);
  printf("1.Bubble sort\n");
  printf("2.Selection sort\n");
  printf("3.Insertion sort\n");
  printf("4.Exit\n");

  printf("Enter choice\n");
  scanf("%d",&flag);
  break;

}
case 3:
{
    printf("Insertion sort \n");
    insertionsort(arr,n);
    printf("1.Bubble sort\n");
    printf("2.Selection sort\n");
    printf("3.Insertion sort\n");
    printf("4.Exit\n");

    printf("Enter choice\n");
    scanf("%d",&flag);
    break;
}
case 4:
{
    printf("Completed");
    exit;
}
}
}