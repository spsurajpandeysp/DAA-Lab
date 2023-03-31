/*
Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
total number of times the array elements are shifted from their place) required for sorting the
array.
*/
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
void insertionSort(int *arr, int n)
{
    int comp=0;
    int shift = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int key = arr[i+1];
        int j=i;
        
        while(j>=0 && key<=arr[j]){
            arr[j+1]=arr[j];
            comp++;
            shift++;
            j--;
        }
        shift++;
        arr[j+1]=key;
    }
    printf("Array After sorting:");
    display(arr,n);
    printf("\n");
    printf("Total no of comparisons are:%d\n",comp);
    printf("Total number of shift are:%d\n",shift);
}
int main()
{
    int arr[100], n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter Array Element: ");
    input(arr, n);
    
    insertionSort(arr,n);
    

    return 0;
}