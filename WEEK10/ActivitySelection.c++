/*I. Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.*/

#include<bits/stdc++.h>
using namespace std;
void input(int *arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
bool cmp(vector<int> a,vector<int> b){
    return a[2]<b[2];
}
vector<int> selectedActivity;
int numOfSelectedActivity(int *start,int *end,int n){
    vector<vector<int>> vt(n,vector<int> (3));
    for(int i=0;i<n;i++){
        vt[i][0]=i+1;
        vt[i][1]=start[i];
        vt[i][2]=end[i];
    }
    sort(vt.begin(),vt.end(),cmp);
    int endTime = vt[0][2];
    selectedActivity.push_back(vt[0][0]);
    int count=1;
    for(int i=0;i<n;i++){
        if(vt[i][1]>=endTime){
            selectedActivity.push_back(vt[i][0]);
            endTime=vt[i][2];
            count++;
        }
    }
    return count;
}
int main(){
    int n,start[100],end[100];
    cout<<"Enter Number of activity:"<<endl;
    cin>>n;
    cout<<"Enter Activity starting time:"<<endl;
    input(start,n);
    cout<<"Enter Activity ending time:"<<endl;
    input(end,n);
    cout<<"No. of non-conflicting activities: "<<numOfSelectedActivity(start,end,n)<<endl;
    cout<<"List of selected activities: ";
    for(int i=0;i<selectedActivity.size();i++){
        cout<<selectedActivity[i]<<" ";
    }
    return 0;
}
