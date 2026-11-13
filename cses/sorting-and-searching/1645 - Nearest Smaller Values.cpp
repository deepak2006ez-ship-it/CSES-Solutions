#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    vector<int>ans;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i=0;i<n;i++){               
             while(!s.empty() && vec[i]<=s.top().first ){
                    s.pop();
    
                }
                if(s.empty()){
                    ans.push_back(0);
                }else{

                    ans.push_back(s.top().second);
                }

                s.push({vec[i],i+1});
        
        
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}