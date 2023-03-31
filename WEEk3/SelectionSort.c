/*Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.*/
#include <stdio.h>
void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selectionSort(int *arr, int n)
{
    int comp=0;
    int swap = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++){
            comp++;
            if(arr[min]>arr[j]){
                min=j;
                
            }
        }
        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        swap++;
    }
    printf("Array After sorting:");
    display(arr,n);
    printf("\n");
    printf("Total no of comparisons are:%d\n",comp);
    printf("Total number of swap are:%d\n",swap);
}
int main()
{
    int arr[100], n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter Array Element: ");
    input(arr, n);
    selectionSort(arr,n);
    

    return 0;
}