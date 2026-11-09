#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    map<int,int>mp;
    int n,k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int  i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i=0;i<k;i++){
        mp[vec[i]]++;
    }
    int idx=0;
    for(int i=k;i<n;i++){
        cout<<mp.size()<<" ";
        mp[vec[idx]]--;
        if(mp[vec[idx]]==0){
            mp.erase(vec[idx]);
        }
        idx++;
        mp[vec[i]]++;
    }
    cout<<mp.size();
    return 0;
}