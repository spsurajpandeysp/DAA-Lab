/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))*/
#include<stdio.h>
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void mergeArray(int *arr,int lb,int mid,int ub){
    int l1 = mid-lb+1;
    int l2 = ub-mid;
    int R[l2];
    int L[l1];
    for(int i=0;i<l1;i++){
        L[i] = arr[lb+i];
    }
    for(int i=0;i<l2;i++){
        R[i]=arr[mid+i+1];
    }
    int i=0;
    int j=0;
    int k =lb;
    while(i<l1 && j<l2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
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
int binarySeach(int *arr,int n,int key){
    int lb = 0;
    int ub = n-1;
    while(lb<ub){
        int mid = (lb+ub)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            lb = mid +1;
        }
        else{
            ub = mid-1;
        }
    }
    return -1; 
}
void twoSum(int *arr,int n ,int key){
    mergeSort(arr,0,n-1);
    int c;
    for(int i=0;i<n;i++){
        if((c=binarySeach(arr,n,key-arr[i]))>=0){
            printf("Numbers are: %d  %d\n",arr[i],arr[c]);
            return ;
        }
    }
    printf("No Such Element Exist:\n");
}
int main(){
    int arr[100],n,key,t;
    printf("Enter Number of test cases:\n");
    scanf("%d",&t);
    while(t--){
        printf("Enter size of array:\n");
        scanf("%d",&n);
        printf("Enter array Element:\n");
        input(arr,n);
        printf("Enter key:\n");
        scanf("%d",&key);
        twoSum(arr,n,key);
        printf("\n");
    }
    return 0;
}