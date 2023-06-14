/*I. Given an array of characters, you have to find distinct characters from this array. Design an
algorithm and implement it using a program to solve this problem using hashing. (Time
Complexity = O(n))
*/
#include<bits/stdc++.h>
using namespace std;
void input(char arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int main(){
    int n;
    map<char,int> freq;
    char arr[100];
    cout<<"Enter number of characters:"<<endl;
    cin>>n;
    cout<<"Enter characters:"<<endl;
    input(arr,n);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(auto i: freq){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
    
}