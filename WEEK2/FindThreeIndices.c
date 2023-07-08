/*Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].*/
#include <stdio.h>
void input(int *arr, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}
void findThreeIndices(int *arr, int n){
    int flag = -1,i = 0, j = 0, k = 0;
    for (int k = 0; k < n; k++){
        i = 0, j = n - 1;
        while (i < j){
            if (arr[i] + arr[j] < arr[k]){
                i++;
            }
            else if (arr[i] + arr[j] > arr[k]){
                j--;
            }
            else{
                printf("Sequence found at positions: %d,%d,%d\n", i+1, j+1, k+1);
                return;
            }
        }
    }
    printf("No sequence found:\n");
}
int main(){
    int arr[100], n, first, last, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter Array Element: ");
    input(arr, n);
    findThreeIndices(arr, n);
    printf("\n");
    return 0;
}