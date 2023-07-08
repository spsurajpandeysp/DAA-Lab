/*II. After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact address of his house in the city.
Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
came up with an amazing idea to help his friends. He draws a graph by looking in to location of
his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
shortest distance and path covering that distance from each of his friend’s location to his house
and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
developed the program that implements BellmanFord algorithm but not sure about correctness of
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
void printBellmanFord(int parent[],int dist[],int V){
    for(int i=0;i<V;i++){
        cout<<i+1<<" ";
        int pt=parent[i];
        while(pt!=-1){
            cout<<pt+1<<" ";
            pt=parent[pt];
        }
        cout<<": "<<dist[i]<<endl;
    }
}
void bellmanFord(int graph[MAX][MAX],int V,int src){
        int dist[V];
        int parent[V];
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
            parent[i]=-1;
        }
        dist[src]=0;
        parent[src]=-1;
        for(int i=0;i<V-1;i++){
            for(int u=0;u<V;u++){
                for(int v=0;v<V;v++){
                    if(graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] <dist[v]){
                        dist[v]=dist[u]+graph[u][v];
                        parent[v]=u;
                    }
                }
            }
        }
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(graph[u][v] && dist[v]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                    cout<<"Graph Contains negative-weight Cycle:"<<endl;
                    return ;
                }
            }
        }
        printBellmanFord(parent,dist,V);
    }
int main(){
    int V=5;
    int src =0;
    int graph[MAX][MAX];
    cout<<"Enter Number of vertices:"<<endl;
    cin>>V;
    cout<<"Enter Adj Matrix:"<<endl;;
    inputAdjMatrix(graph,V);
    cout<<"Enter Source Vertiex:"<<endl;
    cin>>src;
    bellmanFord(graph,V,src);
    return 0;
}