/*I. After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact address of his house in the city.
Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
came up with an amazing idea to help his friends. He draws a graph by looking in to location of
his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
shortest distance and path covering that distance from each of his friend’s location to his house
and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
developed the program that implements Dijkstra’s algorithm but not sure about correctness of
results. Can you also implement the same algorithm and verify the correctness of Akshay’s
results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void inputAdjMatrix(int graph[MAX][MAX],int V){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
}
void printDikstraAlgo(int parent[],int dist[],int V){
    for(int i=0;i<V;i++){
        cout<<i+1<<" ";
        int pt = parent[i];
        while(pt!=-1){
            cout<<pt+1<<" ";
            pt = parent[pt];
        }
        cout<<": "<<dist[i]<<endl;
    }
}
void dijkstrasAlgo(int graph[MAX][MAX],int V,int src){
    int parent[V];
    int dist[V];
    int sptSet[V];
    for(int i=0;i<V;i++){
        parent[i]=-1;
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[src]=0;
    parent[src]=-1;
    for(int i=0;i<V-1;i++){
        int u;
        int minDist=INT_MAX;
        for(int j=0;j<V;j++){
            if(dist[j]<=minDist && !sptSet[j]){
                minDist = dist[j];
                u=j;
            }
        }
        sptSet[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v] && !sptSet[v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
                parent[v]=u;
            }
        }

        
    }
    printDikstraAlgo(parent,dist,V);
}
int main(){
    int V=5;
    int src=0;
    int graph[MAX][MAX];

    dijkstrasAlgo(graph,V,src);
    cout<<"Enter Number of vertices:"<<endl;
    cin>>V;
    cout<<"Enter Adj Matrix:"<<endl;
    inputAdjMatrix(graph,V);
    cout<<"Enter Source:"<<endl;
    cin>>src;

    return 0;

}