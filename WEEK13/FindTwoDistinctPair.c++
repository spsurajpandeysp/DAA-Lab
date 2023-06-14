/*III. Given an array of nonnegative integers, Design an algorithm and implement it using a program
to find two pairs (a,b) and (c,d) such that a*b = c*d, where a, b, c and d are distinct elements of
array*/

#include<bits/stdc++.h>
using namespace std;
void input(int arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void twoPairDistinct(int arr[],int n){
    map<int,pair<int,int>> mp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int product = arr[i]*arr[j];
            if(mp.find(product)!=mp.end()){
                cout<<mp[product].first<<" "<<mp[product].second<<endl;
                cout<<arr[i]<<" "<<arr[j]<<endl;
                return;
            }
            else{
                mp[product]=make_pair(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int n,arr[100];
    cout<<"Enter Number Of Element:"<<endl;
    cin>>n;
    cout<<"Enter Array Element:"<<endl;
    input(arr,n);
    cout<<endl<<"OUTPUT"<<endl;
    twoPairDistinct(arr,n);
    return 0;
}