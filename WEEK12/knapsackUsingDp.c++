/*II. Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. Design an algorithm and implement it using a program to find the list of the selected
items such that the final selected content has weight <= w and has maximum value. Here, you
cannot break an item i.e. either pick the complete item or don't pick it. (0-1 property).
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int dp[MAX][MAX];
void takeInput(int n,int arr[]){
    arr[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
}
void knapsackUsingDp(int n,int weight[],int value[],int knapCap){
    for(int i = 0;i<=n;i++){
        for(int w=0;w<=knapCap;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else if(weight[i-1]>w){
                dp[i][w]=dp[i-1][w];
            }
            else{
                dp[i][w]=max(dp[i-1][w],dp[i-1][w-weight[i-1]]+value[i-1]);
            }
        }
    }
}
int main(){
    vector<int> inclWeight;
    vector<int> inclValue;
    int n,knapCap;
    int weight[100],value[100];
    cout<<"Enter Number of item:"<<endl;
    cin>>n;
    cout<<"Enter Weight Of each item:"<<endl;
    takeInput(n,weight);
    cout<<"Enter value of each item:"<<endl;
    takeInput(n,value);
    cout<<"Enter Knapsack Capacity:"<<endl;
    cin>>knapCap;
    knapsackUsingDp(n,weight,value,knapCap);
    cout<<endl;
    cout<<"Value = "<<dp[n][knapCap];
    int i=n,j=knapCap;
    while(i>0 && j>0){
        if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else{
            inclWeight.push_back(weight[i-1]);
            inclValue.push_back(value[i-1]);
            j=j-weight[i-1];
            i--;
        }
    }
    cout<<endl;
    cout<<"Weight Selected: ";
    for(int i=inclWeight.size()-1;i>=0;i--){
        cout<<inclWeight[i]<<" ";
    }
    cout<<endl;
    cout<<"Values of selected Weight: ";
    for(int i=inclValue.size()-1;i>=0;i--){
        cout<<inclValue[i]<<" ";
    }
    return 0;

}

