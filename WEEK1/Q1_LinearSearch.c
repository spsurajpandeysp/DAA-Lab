/*
Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
*/
#include<stdio.h>
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void linearSearch(int *arr,int n,int key){
    
    int comprarisons = 0;
    int flag=-1;
    for(int i=0;i<n;i++){
        comprarisons++;
        if(arr[i]==key){
            flag = 1;
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
        linearSearch(arr,n,key);
        printf("\n");

    }
    return 0;
}