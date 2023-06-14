/*II. Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
deadline associated with it. You have to design an algorithm and implement it using a program to
find maximum number of tasks that can be completed without crossing their deadlines and also
find list of selected tasks.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> res;
void input(int *arr, int n){
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
}
void selectTask(int *time, int *deadline, int n){
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        v.push_back(make_pair(deadline[i],i));
        
    
    }
    sort(v.begin(), v.end());
    res.push_back(v[0].second + 1);
    int temp = time[v[0].second];
    for (int i = 1; i < n; i++){
        if (deadline[v[i].second] - temp >= time[v[i].second]){
           
            res.push_back(v[i].second + 1);
            temp += time[v[i].second];
        }
    }
}
int main(){
    int n, time[100], deadline[100];
    cout<<"Enter Number of task"<<endl;
    cin >> n;
    cout << "Enter Time taken by each Task:" << endl;
    input(time, n);
    cout << "Enter Deadline of each task :"<<endl;;
    input(deadline, n);
    selectTask(time,deadline,n);
    sort(res.begin(),res.end());
    cout << "Max number of tasks = " << res.size() << endl<<"Selected task number:"<<" ";
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}