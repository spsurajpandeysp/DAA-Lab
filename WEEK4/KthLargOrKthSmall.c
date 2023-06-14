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
void kthLargestAndKthsmallest(int *arr,int n,int kth){
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
    printf("Kth Largest value is: %d\n",arr[n-kth]);
    printf("Kth smallest value is: %d\n",arr[kth-1]);
}
int main(){
    int arr[100],n,kth,t;
    printf("Enter No Of test cases:\n");
    scanf("%d",&t);
    while(t--){
        printf("Enter size of array:\n");
        scanf("%d",&n);
        printf("Enter array element:\n");
        input(arr,n);
        printf("Enter K value: \n");
        scanf("%d",&kth);
        kthLargestAndKthsmallest(arr,n,kth);
    }
    
    return 0;
}