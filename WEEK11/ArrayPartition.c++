/*III. Given a set of elements, you have to partition the set into two subsets such that the sum of
elements in both subsets is same. Design an algorithm and implement it using a program to solve
this problem.*/
#include<bits/stdc++.h>
using namespace  std;
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
bool arrayPartition(int arr[],int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(total+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=n-1;i>=0;i--){
        for(int target = 0;target<=total/2;target++){
            bool incl =0;
            if(target-arr[i]>=0){
                incl = dp[i+1][target-arr[i]];
            }
            bool excl = dp[i+1][target];
            dp[i][target] = incl || excl;
        }
    }
    return dp[0][total/2];
}
int main(){
    int n,arr[100],total=0;
    cout<<"Enter Number Element:"<<endl;
    cin>>n;
    cout<<"Enter Array Element:"<<endl;
    input(arr,n);
    cout<<"OUTPUT:"<<endl;
    if(arrayPartition(arr,n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
    
}