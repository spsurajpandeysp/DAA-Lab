/*YGiven an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and print it.
 (Time Complexity = O(n)) (Hint: Use counting sort*/
#include<stdio.h>
void input(char arr[]){
    scanf("%s",arr);
}
void display(char arr[]){
    printf("%s \n",arr);
}
void MaxFreqAlpha(char arr[]){
    int count[26]={0};
    int i=0;
    while(arr[i]!='\0')
    {
        count[arr[i]-97]=count[arr[i]-97]+1;
        i++;
    }
    int max = 0;
    for(int i=0;i<26;i++){
        if(count[i]>count[max]){
            max=i;
        }
    }
    printf("Maximum Frequency Alphabate is:%c %d\n",max+97,count[max]);
}
int main(){
    char arr[100];
    printf("Enter array Element:\n");
    input(arr);
    printf("Array Element are:\n");
    display(arr);
    MaxFreqAlpha(arr);
    return 0;
}