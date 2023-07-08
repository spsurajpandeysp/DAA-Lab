/*Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
matrices together. To find the optimal solution, you need to find the order in which these
matrices should be multiplied. */
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int M[MAX][MAX];
int S[MAX][MAX];
void input(int *p,int n){
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
}
void matrixChainMultiplication(int *P,int n){
    for(int i=1;i<n;i++){
        M[i][i]=0;
    }
    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){
            int j=i+d;
            M[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int cal=M[i][k]+M[k+1][j]+P[i-1]*P[k]*P[j];
                if(M[i][j]>cal){
                    S[i][j]=k;
                    M[i][j]=cal;
                }
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter Number of Matrix:"<<endl;
    cin>>n;
    n++;
    int P[n];
    cout<<"Enter Matrix no of row or column:"<<endl;
    input(P,n);
    matrixChainMultiplication(P,n);
    cout<<M[1][n-1]<<endl;
    return 0;
}