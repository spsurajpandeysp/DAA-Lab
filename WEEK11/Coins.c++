/*II. Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
For a given value N, you have to Design an algorithm and implement it using a program to find
number of ways in which these coins can be added to make sum value equals to N.*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void input(int arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int coinChange(int coinValues[],int numCoins,int N){
    int dp[MAX]={0};
    dp[0]=1;
    for(int i=0;i<numCoins;i++){
        for(int j=coinValues[i];j<=N;j++){
            dp[j]+=dp[j-coinValues[i]];
        }
    }
    return dp[N];
}
int main(){
    int numCoins,coinValue[MAX],N;
    cout<<"Enter number of coins:"<<endl;
    cin>>numCoins;
    cout<<"Enter coins value:"<<endl;
    input(coinValue,numCoins);
    cout<<"Enter target value:"<<endl;
    cin>>N;
    cout<<"Number Of Ways: "<<coinChange(coinValue,numCoins,N)<<endl;
    return 0;
}