#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int ans=0;
    int curr=0;
    int st=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        
        mp[vec[i]]++;
            while( mp[vec[i]]>1){
                mp[vec[st]]--;
                st++;
                
            }
        
        ans=max(ans,i-st+1);

    }
    cout<<ans<<endl;
    return 0;
}