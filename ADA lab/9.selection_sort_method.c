#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
                }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}
int main(){
    int n;
    printf("enter the number of elements:");
    scanf("%d",&n);
int arr[n];
srand(time(NULL));
for(int i=0;i<n;i++){
    arr[i]=rand() %1000;
}
clock_t start_time=clock();
selectionsort(arr,n);
clock_t end_time=clock();
double time_taken=((double)(end_time-start_time))/CLOCKS_PER_SEC;
printf("time taken to sort %d elements:%lf seconds",n,time_taken);
}