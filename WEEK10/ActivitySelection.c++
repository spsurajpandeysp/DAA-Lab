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
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.second.second<b.second.second;
}
vector<int> selectedActivity;
int numOfSelectedActivity(int *start,int *end,int n){
    vector<pair<int,pair<int,int>>> vp;
    for(int i=0;i<n;i++){
        vp.push_back(make_pair(i+1,make_pair(start[i],end[i])));
    }
    sort(vp.begin(),vp.end(),cmp);

    int endTime = vp[0].second.second;
    selectedActivity.push_back(vp[0].first);
    int count=1;
    for(int i=0;i<n;i++){
        if(vp[i].second.first>=endTime){
            selectedActivity.push_back(vp[i].first);
            endTime=vp[i].second.second;
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
