/*I. Given a graph, Design an algorithm and implement it using a program to implement FloydWarshall all pair shortest path algorithm.*/
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define MAX 100
int graph[MAX][MAX];
int dp[MAX][MAX];
void createAdjMatrix(int vertices){
    string str;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>>str;
            if(str=="INF"){
                graph[i][j]=INF;
            }
            else{
                graph[i][j]=stoi(str);
            }
        }
    }
}

void printShortestPathMatrix(int vertices ){
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if(dp[i][j]==INT_MAX){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
void floydWarshalAlgo(int vertices){
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            dp[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<vertices;k++){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                if(dp[i][j]>dp[k][j]+dp[i][k] && dp[k][j]!=INF && dp[i][k]!=INF){
                    dp[i][j] = dp[k][j]+dp[i][k];
                }
            }
        }
    }
}
int main(){
    int vertices;
    cout<<"Enter Number of vertices in a Graph:"<<endl;
    cin>>vertices;
    cout<<"Enter Adj Matrix of a Graph:"<<endl;
    createAdjMatrix(vertices);
    floydWarshalAlgo(vertices);
    cout<<endl<<"Shortest Path Matrix"<<endl;
    printShortestPathMatrix(vertices);
    return 0;
}