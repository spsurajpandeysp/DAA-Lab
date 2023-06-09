/*You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))*/
#include<stdio.h>
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void commonElement(int *arr1,int m,int *arr2,int n){
    int i=0;
    int j=0;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            printf("%d ",arr1[i]);
            i++;j++;
        }
    }
}
int main(){
    int arr1[100],n,m,arr2[100];
    printf("Enter size of First array:\n");
    scanf("%d",&m);
    printf("Enter Element first array:\n");
    input(arr1,m);
    BubbleSort(arr1,m);
    printf("Enter size of First array:\n");
    scanf("%d",&n);
    printf("Enter Element of second array:\n");
    input(arr2,n);
    printf("Common Element are:\n");
    commonElement(arr1,m,arr2,n);
    return 0;
}