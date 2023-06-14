/*Given two sequences, Design an algorithm and implement it using a program to find the length
of longest subsequence present in both of them. A subsequence is a sequence that appears in the
same relative order, but not necessarily contiguous.
*/
#include<iostream>
using namespace std;
#define MAX 100
int c[MAX][MAX];
char b[MAX][MAX];
void displayDirection(int n,int m){
    cout<<"Direction Matrix:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void displayValue(int n,int m){
    cout<<"Value Matrix:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void LCS(string s1,string s2){
    int n = s1.length();
    int m = s2.length();
    for(int i=0;i<=n;i++){
        c[i][0]=0;
        b[i][0]='0';
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
        b[0][i]='0';
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]  =c[i-1][j-1]+1;
                b[i][j] = 'D';
            }
            else if(c[i-1][j]>= c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j] = 'U';
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }
    }
}
int main(){
    string s1,s2;
    string ans;
    cout<<"Enter First String:"<<endl;
    cin>>s1;
    cout<<"Enter second String:"<<endl;
    cin>>s2;
    LCS(s1,s2);
    int i=s1.size(),j=s2.size();
    while(j>0 && i>0){
        if(b[i][j]=='D'){
            ans = s1[i-1]+ans;
            i--;
            j--;
        }
        else if(b[i][j]=='U'){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<"Longest Common Subsequence: "<<ans<<endl;
    cout<<"Length = "<<c[s1.size()][s2.size()]<<endl;
    return 0;
}