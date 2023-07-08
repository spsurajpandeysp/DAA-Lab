/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] <
key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching)
*/
#include<stdio.h>
#include<math.h>
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void jumpSearch(int *arr,int n,int key){
    int comprarisons = 0,flag=-1,start=0,end,jump = sqrt(n);
    end=jump;
    while(arr[end]<=key && end<n){
        start = end;
        end = jump+end;
        comprarisons++;
        if(end>n-1){
            end = n;
        }
    }
    for(int i=start;i<end;i++){
        comprarisons++;
        if(arr[i]==key){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Present %d",key);
    }
    else{
        printf("Not Present %d",key);
    }
    printf("\nTotal No Of Comparisons: %d\n",comprarisons);
    
}

int main(){
    int arr[100],n,testCases,key;
    printf("Enter No of Test Cases:\n");
    scanf("%d",&testCases);
    for(int i=0;i<testCases;i++){
        printf("%d Test Case:\n",i+1);
        printf("INPUT\n");
        printf("Enter size of array: ");
        scanf("%d",&n);
        printf("Enter Array Element: ");
        input(arr,n);
        printf("Enter Element you Want to Find: ");
        scanf("%d",&key);
        printf("\nOUTPUT\n");
        jumpSearch(arr,n,key);
        printf("\n");

    }
    return 0;
}