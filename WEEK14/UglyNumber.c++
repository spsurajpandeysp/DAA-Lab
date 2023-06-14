#include<bits/stdc++.h>
using namespace std;
int nthUglyNumber(int n){
    int dp[n];
    dp[0]=1;
    int p1,p2,p3;
    p1=p2=p3=0;
    int two,three,five;
    for(int i=1;i<n;i++){
        two = dp[p1]*2;
        three = dp[p2]*3;
        five = dp[p3]*5;
        dp[i]=min(two,min(three,five));
        if(dp[i]==two){
            p1++;
        }
        if(dp[i]==three){
            p2++;
        }
        if(dp[i]==five){
            p3++;
        }
    }
    return dp[n-1];
}
int main(){
    int t,n;
    cout<<"Enter Number of test Case:"<<endl;
    cin>>t;
    while(t--){
        cout<<"Enter Number:"<<endl;
        cin>>n;
        cout<<"OUTPUT"<<endl;
        cout<<nthUglyNumber(n)<<endl;
    }
    return 0;
}