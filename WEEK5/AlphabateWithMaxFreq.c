/*YGiven an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and print it.
 (Time Complexity = O(n)) (Hint: Use counting sort*/
#include<stdio.h>
void input(char arr[],int n){
    for(int i=0;i<n;i++){
        scanf("%s",&arr[i]);
    }
}
void MaxFreqAlpha(char arr[],int n){
    int count[26]={0};
    for(int i=0;i<n;i++){
        count[arr[i]-97]=count[arr[i]-97]+1;
    }
    int max = 0;
    for(int i=0;i<26;i++){
        if(count[i]>count[max]){
            max=i;
        }
    }
    if(count[max]==1){
        printf("No Duplicates Present:\n");
        return;
    }
    else{
        printf("Maximum Frequency Alphabet is:%c-%d\n",max+97,count[max]);
    }
}
int main(){
    int t,n;
    char arr[100];
    printf("Enter Number of test cases:\n");
    scanf("%d",&t);
    while(t--){
        printf("Enter Number of characters:\n");
        scanf("%d",&n);
        printf("Enter characters:\n");
        input(arr,n);
        MaxFreqAlpha(arr,n);
    }
    return 0;
}