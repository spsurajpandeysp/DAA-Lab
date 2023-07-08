/*III. Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array*/
#include<iostream>
using namespace std;
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void majorityElement(int *arr,int n){
    int ansIndex = 0;
    int count =1;
    for(int i=1;i<n;i++){
        if(arr[ansIndex]==arr[i]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            ansIndex = i;
            count = 1;
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(arr[ansIndex]==arr[i]){
            count++;
        }
    }
    cout<<"OUTPUT:"<<endl;
    if(count>=n/2){
        cout<<"YES"<<endl<<arr[ansIndex];
    }
    else{
        cout<<"No"<<endl;
    }
}
int main(){
    int n,arr[100];
    cout<<"Enter Number of element:"<<endl;
    cin>>n;
    cout<<"Enter Array Element:"<<endl;
    input(arr,n);
    majorityElement(arr,n);
    return 0;
}