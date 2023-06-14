/*III. Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.*/

#include<bits/stdc++.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
void addEdge(int vertices){
    for(int i=0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }
}
bool DFS(int current,int vertices){
    visited[current] = 1;
    recStack[current]=1;
    
    for(int i=0;i<vertices;i++){
        if(recStack[i] && graph[current][i]){
            return true;
        }
        else if(graph[current][i] && !visited[i]){
            if(DFS(i,vertices)){
                return true;
            }
        }
    }
    recStack[current]=0;
    return false;
}
int main(){
    int vertices;
    printf("Enter number of vertices:\n");
    scanf("%d",&vertices);
    printf("Enter the adj Matrix:\n");
    addEdge(vertices);
    for(int i=0;i<vertices;i++){
        recStack[i]=0;
        visited[i]=0;
    }

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            if(DFS(i,vertices)){
                printf("Yes Cycle Exists:\n");
                return 0;
            }
        }
    }
    printf("No Cycle Exists:\n");
    
    return 0;
}