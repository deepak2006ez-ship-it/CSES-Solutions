#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<long long,long long>mp;
    int n;
    cin>>n;
    mp[0]++;
    long long ans=0;
    long long currSum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        currSum+=x;
        
        long long valEx=((currSum%n)+n)%n;
        if(mp.find(valEx)!=mp.end()){
            ans+=mp[valEx];
        }
        mp[valEx]++;
        



    }
    cout<<ans;
    return 0;
}