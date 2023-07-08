/*Assume that a project of road construction to connect some cities is given to your friend. Map of
these cities and roads which will connect them (after construction) is provided to him in the form
of a graph. Certain amount of rupees is associated with construction of each road. Your friend
has to calculate the minimum budget required for this project. The budget should be designed in
such a way that the cost of connecting the cities should be minimum and number of roads
required to connect all the cities should be minimum (if there are N cities then only N-1 roads
need to be constructed). He asks you for help. Now, you have to help your friend by designing an
algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)*/
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
int primAlgo(int graph[MAX][MAX],int numCity){
    int parent[numCity];
    int MST[numCity];
    int key[numCity];
    for(int i=0;i<numCity;i++){
        key[i]=INT_MAX,MST[i]=false,parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<numCity;i++){
        int u;
        int min = INT_MAX;
        for(int j=0;j<numCity;j++){
            if(MST[j]==false && key[j]<min){
                u=j;
                min=key[j];
            }
        }
        MST[u]=true;
        for(int j=0;j<numCity;j++){
            if(graph[u][j] && !MST[j] && graph[u][j]<key[j]){
                parent[j] = u,key[j] = graph[u][j];
            }
        }
    }
    int minCost=0;
    for(int i=1;i<numCity;i++){
        minCost+=key[i];
    }
    return minCost;
}
int main(){
    int graph[MAX][MAX];
    int numCity=7;
    cout<<"Enter Number of city:"<<endl;
    cin>>numCity;
    cout<<"Enter Adjacency Matric:"<<endl;
    inputAdjMatrix(graph,numCity);
    int minCost=primAlgo(graph,numCity); 
    cout<<"Minimum Spanning Weight: "<<minCost<<endl;
    return 0;
}