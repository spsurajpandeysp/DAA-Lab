/*Assume that a project of road construction to connect some cities is given to your friend. Map of
these cities and roads which will connect them (after construction) is provided to him in the form
of a graph. Certain amount of rupees is associated with construction of each road. Your friend
has to calculate the minimum budget required for this project. The budget should be designed in
such a way that the cost of connecting the cities should be minimum and number of roads
required to connect all the cities should be minimum (if there are N cities then only N-1 roads
need to be constructed). He asks you for help. Now, you have to help your friend by designing an
algorithm which will find minimum cost required to connect these cities. (use kruskal's algorithm)*/
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
int findParent(int parent[],int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);
}
void unionSet(int rank[],int parent[],int u,int v){
    u = findParent(parent,u);
    v = findParent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        rank[u]++;
        parent[v]=u;
    }
}
bool cmp(vector<int> a,vector<int> b){
    return a[2]<b[2];
}
int kruskalAlgo(int graph[MAX][MAX],int numCity){
    int parent[numCity]={-1},rank[numCity]={0},minWeight=0;
    vector<vector<int>> edges;
    for(int i=0;i<numCity;i++){
        parent[i]=i;
    }
    for(int i=0;i<numCity;i++){
        for(int j=0;j<numCity;j++){
            if(graph[i][j]){
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(graph[i][j]);
                edges.push_back(temp);

            }
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    for(int i=0;i<edges.size();i++){
        if(findParent(parent,edges[i][0])!=findParent(parent,edges[i][1])){
            minWeight+=edges[i][2];
            unionSet(rank,parent,edges[i][0],edges[i][1]);
        }
    }
    return minWeight;
}
int main(){
    int graph[MAX][MAX];
    int numCity=7;
    cout<<"Enter Number of city:"<<endl;
    cin>>numCity;
    cout<<"Enter Adjacency Matric:"<<endl;
    inputAdjMatrix(graph,numCity);
    int minCost=kruskalAlgo(graph,numCity); 
    cout<<"Minimum Spanning Weight: "<<minCost<<endl;
    return 0;
}