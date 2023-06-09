/*III. Given a string of characters, design an algorithm and implement it using a program to print all
possible permutations of the string in lexicographic order.*/
#include<bits/stdc++.h>
using namespace std;
void allPermutation(string str,vector<string> &ans,int n,int i){
    if(i>=n){
        ans.push_back(str);
        return ;
    }
    for(int j=i;j<n;j++){
        swap(str[j],str[i]);
        allPermutation(str,ans,n,i+1);
        swap(str[j],str[i]);
    }
}
int main(){
    string str;
    vector<string> ans;
    cout<<"Enter String:"<<endl;
    cin>>str;
    int n = str.size();    
    allPermutation(str,ans,n,0);
    sort(ans.begin(),ans.end());
    cout<<endl<<"OUTPUT"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}