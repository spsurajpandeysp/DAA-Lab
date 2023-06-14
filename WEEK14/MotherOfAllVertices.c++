/*II.Given a directed graph, write an algorithm and a program to find mother vertex in a graph. A
mother vertex is a vertex v such that there exists a path from v to all other vertices of the graph.*/#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int isPath  = 10;
void addEdge(int vertices){
    for(int i=0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            cin>>graph[i][j];
        }
    }
}

int main(){
    int vertices,current,destination;
    cout<<"Enter number of vertices:"<<endl;
    scanf("%d",&vertices);
    cout<<"Enter the adj Matrix:\n"<<endl;
    addEdge(vertices);
    return 0;
}