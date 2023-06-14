/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.*/
#include<stdio.h>
int comparison = 0;
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
void mergeArray(int *arr,int lb,int mid,int ub){
    int l1= mid - lb+1;
    int l2 = ub - mid;
    int L[l1];
    int R[l2];
    for(int i=0;i<l1;i++){
        L[i]=arr[lb+i];
    }
    for(int i=0;i<l2;i++){
        R[i]=arr[mid+i+1];
    }
    int  i= 0,j=0,k=lb;
    while(i<l1 && j<l2){
        comparison++;
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<l1){
        arr[k++]=L[i++];
    }
    while(j<l2){
        arr[k++]=R[j++];
    }
}
void mergeSort(int *arr,int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        mergeArray(arr,lb,mid,ub);
    }
}
int main(){
    int arr[100],n,t;
    printf("Enter Number of test cases\n");
    scanf("%d",&t);
    while(t--){
        comparison=0;
        printf("Enter size of array:\n");
        scanf("%d",&n);
        printf("Enter array element:\n");
        input(arr,n);
        mergeSort(arr,0,n-1);
        printf("Array element after sorting:\n");
        display(arr,n);
        printf("Total Number of copmarison: %d",comparison);
        printf("\n");
    }
    return 0;
}