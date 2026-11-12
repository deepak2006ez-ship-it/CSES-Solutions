#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        mp[vec[i]]=i;
    }
    int round=1;
    for(int i=1;i<n;i++){
        if(mp[i+1]<mp[i]){
            round++;
        }
    }
    cout<<round;
    return 0;
}