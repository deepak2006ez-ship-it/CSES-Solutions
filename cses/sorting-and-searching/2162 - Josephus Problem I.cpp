#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int skip=q.front();
        q.pop();
        q.push(skip);
        if(!q.empty()){
            int remove=q.front();
            ans.push_back(remove);
            q.pop();
        }

    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}