/*II. Given an array of integers of size n, design an algorithm and write a program to check whether
this array contains duplicate within a small window of size k < n.
*/

#include<bits/stdc++.h>
using namespace std;

void input(int arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
bool duplicateWithinSmallWindow(int arr[],int n,int w){
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        if(st.find(arr[i])!=st.end()){
            return true;
        }
        st.insert(arr[i]);
        if(i>=w){
            st.erase(arr[i-w]);
        }
    }
    return false;
}
int main(){
    int n,arr[100],t,w;
    cout<<"Enter Number Of Test cases:"<<endl;
    cin>>t;
    while(t--){
        cout<<"Enter Number of element:"<<endl;
        cin>>n;
        cout<<"Enter Array Element:"<<endl;
        input(arr,n);
        cout<<"Enter Size of window:"<<endl;
        cin>>w;
        if(duplicateWithinSmallWindow(arr,n,w)){
            cout<<"Duplicate present in window "<<w<<endl;
        }
        else{
            cout<<"Duplicate Not present in window "<<w<<endl;
        }
    }
    return 0;
}