/*II. Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. You have to Design an algorithm and implement it using a program to find the list of the
selected items such that the final selected content has weight w and has maximum value. You can
take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
only a fraction xi of item i, where 0 ≤xi≤ 1.*/
#include<bits/stdc++.h>
using namespace std;
void takeInput(int n,int arr[]){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
bool cmp(vector<double> a,vector<double> b){
    return a[0]>b[0];
}
vector<pair<int,int>> it_wt;
double fractionalKnapsack(int n,int weight[],int value[],int knapCap){
    vector<vector<double>> item(n,vector<double> (4));
    for(int i=0;i<n;i++){
        double perUnitValue = (1.0*value[i])/weight[i];
        item[i][0]=perUnitValue;
        item[i][1]=i+1;
        item[i][2]=value[i];
        item[i][3]=weight[i];
    }
    sort(item.begin(),item.end(),cmp);
    double totalValue =0;
    for(int i=0;i<n;i++){
        if(item[i][3]>knapCap && knapCap!=0){
            it_wt.push_back(make_pair(item[i][1],knapCap));
            totalValue+=knapCap*item[i][0];
            break;
        }
        else{
            totalValue +=item[i][2];
            knapCap = knapCap - item[i][3];
            it_wt.push_back(make_pair(item[i][1],item[i][3]));
        }
    }
    return totalValue;
}
int main(){
    int n,knapCap;
    int weight[100],value[100];
    cout<<"Enter Number of item:"<<endl;
    cin>>n;
    cout<<"Enter Weight Of each item:"<<endl;
    takeInput(n,weight);
    cout<<"Enter value of each item:"<<endl;
    takeInput(n,value);
    cout<<"Enter Knapsack Capacity:"<<endl;
    cin>>knapCap;
    cout<<"Maximum value:"<<fractionalKnapsack(n,weight,value,knapCap);
    cout<<endl;
    cout<<"item-weight"<<endl;
    for(int i=0;i<it_wt.size();i++){
        cout<<it_wt[i].first<<"-"<<it_wt[i].second<<endl;
    }
    return 0;
}

