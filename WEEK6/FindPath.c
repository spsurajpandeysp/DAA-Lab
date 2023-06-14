/*Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)*/

#include<stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int isPath  = 10;
void addEdge(int vertices){
    for(int i=0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }
}
void DFS(int current,int destination,int vertices){
    visited[current] = 1;
    if(current==destination){
        isPath = 1;
        return ;
    }
    else{
        for(int i=0;i<vertices;i++){
            if(graph[current][i] && !visited[i]){
                DFS(i,destination,vertices);
            }
        }
    }
}
int main(){
    int vertices,current,destination;
    printf("Enter number of vertices:\n");
    scanf("%d",&vertices);
    printf("Enter the adj Matrix:\n");
    addEdge(vertices);
    printf("Enter current vertices:\n");
    scanf("%d",&current);
    printf("Enter destination vertices:\n");
    scanf("%d",&destination);
    DFS(current,destination,vertices);
    if(isPath){
        printf("YES Path Exists:\n");
    }
    else{
        printf("No Path Exists:\n");
    }
    return 0;
}