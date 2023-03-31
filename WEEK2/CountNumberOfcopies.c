/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/
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
int countCopies(int *arr,int n,int key,int mode){
    bubbleSort(arr,n);
    int lb=0,ub=n-1;
    int ans=-1;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(key==arr[mid]){
            ans = mid;
            if(mode){
                ub=mid-1;
            }
            else{
                lb=mid+1;
            }
        }
        else if(key<arr[mid]){
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[100],n,first,last,key;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter Array Element: ");
    input(arr,n);
    printf("Enter Element you Want to Find: ");
    scanf("%d",&key);
    printf("\nOUTPUT\n");
    first = countCopies(arr,n,key,1);
    last = countCopies(arr,n,key,0);
    if(first<0 && last<0){
        printf("%d Not Present:\n",key);
    }
    else{
        printf("%d Present:-%d",key,last-first+1);
    }

    printf("\n");
    return 0;
}