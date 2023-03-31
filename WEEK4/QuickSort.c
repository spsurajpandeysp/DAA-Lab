/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.*/
#include<stdio.h>
int comparisons = 0;
int swap = 0;
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void display(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int partition(int *arr,int lb,int ub){
    int pivot = arr[ub];
    int i=lb-1;
    for(int j=lb;j<ub;j++){
        comparisons++;
        if(arr[j]<=pivot){
            i++;
            swap++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    swap++;
    int temp = arr[i];
    arr[i]=arr[ub];
    arr[ub]=temp;
    return i;
}
void quickSort(int *arr,int lb,int ub){
    if(lb<ub){
        int pivot = partition(arr,lb,ub);
        quickSort(arr,lb,pivot-1);
        quickSort(arr,pivot+1,ub);
    }
}
int main(){
    int arr[100],n;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    input(arr,n);
    printf("Array element before sorting:\n");
    display(arr,n);
    quickSort(arr,0,n-1);
    printf("Array element after sorting:\n");
    display(arr,n);
    printf("Swap: %d\n",swap);
    printf("Comparisons:%d\n",comparisons);
    return 0;
}