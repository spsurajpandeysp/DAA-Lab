/*
Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
*/
#include <stdio.h>
void input(int *arr, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}
int countPairDiff(int *arr, int n, int key){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int diff = arr[i] - arr[j];
            if (diff == key || diff == -key){
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int arr[100], n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter Array Element: ");
    input(arr, n);
    printf("Enter key:");
    scanf("%d", &key);
    int c = countPairDiff(arr, n, key);
    printf("Total Number of pair are: %d\n", c);
    return 0;
}