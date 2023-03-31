/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).*/
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
void bubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void binarySearch(int *arr,int n,int key){
    bubbleSort(arr,n);
    int comprarisons = 0,flag=-1,lb=0,ub=n-1,mid;
    while(lb<=ub){
        mid = (lb+ub)/2;
        comprarisons++;
        if(arr[mid]==key){
            flag=1;
            break;
        }
        else if(arr[mid]>key){
            ub = mid-1;
        }
        else{
            lb = lb+1;
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
        binarySearch(arr,n,key);
        printf("\n");

    }
    return 0;
}