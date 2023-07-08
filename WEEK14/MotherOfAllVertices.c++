/*II.Given a directed graph, write an algorithm and a program to find mother vertex in a graph. A
mother vertex is a vertex v such that there exists a path from v to all other vertices of the graph.*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void inputAdjMatrix(int graph[MAX][MAX],int V){
    for(int i=0;i<V;i++){
        for(int j = 0;j<V;j++){
            cin>>graph[i][j];
        }
    }
}

void dfs(int graph[MAX][MAX],int V,int visited[],int s){
    visited[s]=true;
    for(int i=0;i<V;i++){
        if(!visited[i] && graph[s][i]){
            dfs(graph,V,visited,i);
        }
    }
}

int main(){
    int V;
    int graph[MAX][MAX];
    cout<<"Enter number of vertices:"<<endl;
    cin>>V;
    cout<<"Enter the adj Matrix:\n"<<endl;
    inputAdjMatrix(graph,V);
    int ans;
    int visited[MAX]={false};
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(graph,V,visited,i);
            ans=i;
        }
    }
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    dfs(graph,V,visited,ans);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            cout<<"No Mother vertex is present:"<<endl;
            return 0;
        }
    }
    cout<<"Mother Vertex is:"<<ans<<endl;
    return 0;
}