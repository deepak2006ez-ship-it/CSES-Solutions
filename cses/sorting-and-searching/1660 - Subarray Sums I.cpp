#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<long long,long long>mp;
    int n,requiredSum;
    cin>>n>>requiredSum;
    mp[0]++;
    long long currSum=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        currSum+=x;
        
        long long sumC=currSum-requiredSum;
        if(mp.find(sumC)!=mp.end()){
            ans+=mp[sumC];
        }
        mp[currSum]++;
        



    }
    cout<<ans;
    return 0;
}