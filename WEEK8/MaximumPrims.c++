/*III. Assume that same road construction project is given to another person. The amount he will earn
from this project is directly proportional to the budget of the project. This person is greedy, so he
decided to maximize the budget by constructing those roads who have highest construction cost.
Design an algorithm and implement it using a program to find the maximum budget required for
the project.*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void inputAdjMatrix(int graph[MAX][MAX], int numCity){
    for(int i=0;i<numCity;i++){
        for(int j=0;j<numCity;j++){
            cin>>graph[i][j];
        }
    }
}
int primsMaximun(int graph[MAX][MAX],int numCity){
    int parent[numCity];
    int key[numCity];
    int MST[numCity];

    for(int i=0;i<numCity;i++){
        parent[i]=-1;
        key[i]=INT_MIN;
        MST[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<numCity;i++){
        int u;
        int max=INT_MIN;
        for(int j=0;j<numCity;j++){
            if(!MST[j] && key[j]>max){
                u = j;
                max = key[j];
            }
        }

        MST[u]=true;
        for(int j=0;j<numCity;j++){
            if(graph[u][j] && !MST[j] && graph[u][j]>key[j]){
                parent[j]=u;
                key[j]=graph[u][j];
            }
        }
    }
    int maxCost=0;
    for(int i=0;i<numCity;i++){
        maxCost+=key[i];
    }

    return maxCost;
}
int main(){
    int numCity=7;
    
    int graph[MAX][MAX];
    cout<<"Enter Number of city:"<<endl;
    cin>>numCity;
    cout<<"Enter Adjacency Matrix:"<<endl;
    inputAdjMatrix(graph,numCity);
    int maxCost= primsMaximun(graph,numCity);
    cout<<"Maximum Spanning Weight:"<<maxCost<<endl;
    return 0;

}