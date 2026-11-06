#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;
int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);
}
void recursiveApproach(string &s,unordered_set<string>&ch,vector<string>&ans,int idx){
    if(idx==s.size()){
        if(ch.find(s)==ch.end()){
            ans.push_back(s);
            ch.insert(s);
        }
        return;

    }
    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        recursiveApproach(s,ch,ans,idx+1);
        swap(s[i],s[idx]);
        
    }
    
}
int main(){
    unordered_map<char,int>mp;
    string s;
    cin>>s;
    int total_Permutation=factorial(s.size());
    for(auto &ch:s){
        mp[ch]++;
    }
    for(auto &ch:s){
        if(mp.find(ch)!=mp.end()){
            if(mp[ch]>1){
                total_Permutation/=factorial(mp[ch]);
                mp.erase(ch);
            }
        }
    }
    cout<<total_Permutation<<endl;
    sort(s.begin(),s.end());
    unordered_set<string>ch;
    vector<string>ans;
    int idx=0;
    recursiveApproach(s,ch,ans,idx);
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }



    
    return 0;
}