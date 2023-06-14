/*
Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))
*/
#include <stdio.h>
void input(int *arr, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}
void mergeArray(int *arr,int lb,int mid,int ub){
    int l2 = ub-mid;
    int l1 = mid-lb+1;
    int L[l1];
    int R[l2];
    for(int i=0;i<l1;i++){
        L[i]=arr[i+lb];
    }
    for(int i=0;i<l1;i++){
        R[i]=arr[i+mid+1];
    }
    int k = lb;
    int i=0;
    int j=0;
    while(i<l1 && j<l2){
        if(L[i]<R[j]){
            arr[k++]=L[i++];
        }
        else {
            arr[k++]=R[j++];
        }
    }
    while(i<l1){
        arr[k++] = L[i++];

    }
    while(j<l2){
        arr[k++] = R[j++];
    }
}
void mergeSort(int *arr, int lb ,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        mergeArray(arr,lb,mid,ub);
    }
}
void findDuplicateEle(int *arr,int n){
    int lb=0;
    int ub=n-1;
    mergeSort(arr,lb,ub);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            printf("YES:\n");
            return;
        }
    }
    printf("NO:\n");
}
int main(){
    int arr[100], n, key,t;
    printf("Enter Number of test case:\n");
    scanf("%d",&t);
    while(t--){
         printf("Enter size of array: ");
        scanf("%d", &n);
        printf("Enter Array Element: ");
        input(arr, n);
        findDuplicateEle(arr,n);
    }
    return 0;
}