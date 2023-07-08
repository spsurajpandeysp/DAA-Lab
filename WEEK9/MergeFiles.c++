/*III. Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
program to merge all these files into single file with minimum computation. For given two files
A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy
approach)*/
#include<bits/stdc++.h>
using namespace std;
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int minimumComputationForMergeFile(int *files,int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(files[i]);
    } 
    int ans = 0;
    while(pq.size()>1){
        int f1 = pq.top();
        pq.pop();
        int f2 = pq.top();
        pq.pop();
        ans = ans+f1+f2;
        pq.push(f1+f2);
    }
    return ans;
}
int main(){
    int n,files[100];
    cout<<"Enter Number of Files:"<<endl;
    cin>>n;
    cout<<"Enter file size:"<<endl;
    input(files,n);
    cout<<minimumComputationForMergeFile(files,n);
    return 0;
}