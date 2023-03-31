/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/
#include<stdio.h>

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
void kthLargestAndKthsmallest(int *arr,int n,int kthLar,int Kthsmall){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    int count[max+1];
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        ++count[arr[i]];
    }
    for(int i=1;i<=max;i++){
        count[i]=count[i-1]+count[i];
    }
    int ans[n];
    for(int i=0;i<n;i++){
        ans[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
    printf("Kth Largest value is: %d\n",arr[n-kthLar]);
    printf("Kth smallest value is: %d\n",arr[Kthsmall-1]);
}
int main(){
    int arr[100],n,kthLar,kthSmall;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array element:\n");
    input(arr,n);
    printf("Array element before sorting:\n");
    display(arr,n);
    printf("Enter Kth Largest: \n");
    scanf("%d",&kthLar);
    printf("Enter Kth Smallest: \n");
    scanf("%d",&kthSmall);
    kthLargestAndKthsmallest(arr,n,kthLar,kthSmall);
    return 0;
}