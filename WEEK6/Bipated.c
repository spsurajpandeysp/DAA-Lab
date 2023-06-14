/*Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. (Hint: use BFS)
*/
#include<stdio.h>
#include<stdbool.h>
#define MAX 100
int graph[MAX][MAX];
int color[MAX];
bool isBipartit = true;
void createAdjMatrix(int vertices){
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }
}
void BFS(int start,int vertices){
    int queue[MAX] ,rear=-1,front =-1;
    queue[++rear] = start;
    front++;
    while(front<=rear){
        int current = queue[front++];
        for(int i=0;i<vertices;i++){
            if(graph[current][i] && color[i]==-1){
                color[i]=1-color[current];
              
                queue[++rear]=i;
            }
            else if(graph[current][i] && color[i]==color[current]){
                isBipartit = false;
                return ;
            }
        }
    }
}
int main(){
    int vertices;
    printf("Enter number of vertices:\n");
    scanf("%d",&vertices);
    printf("Enter graph adj matrix:\n");
    createAdjMatrix(vertices);
    for(int i=0;i<MAX;i++){
        color[i]=-1;
    }
    for(int i=0;i<vertices;i++){
        if(color[i]==-1){
            BFS(i,vertices);
        }
    }
    if(isBipartit){
        printf("YES Bipartite:\n");
    }
    else{
        printf("NOT Bipartite:\n");
    }


}