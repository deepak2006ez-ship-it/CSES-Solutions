#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int size,target;
    cin>>size>>target;
    vector<pair<int,int>>vec;
    
    vector<int>ans;
    for(int i=0;i<size;i++){
        int x;
        cin>>x;
        vec.push_back({x,i});
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<size;i++){
        int newTarget=target-vec[i].first;
        if(newTarget>0){
            int j=i+1,k=size-1;
            while(j<k){
                if(vec[j].first+vec[k].first==newTarget){
                    ans.push_back(vec[i].second+1);
                    ans.push_back(vec[j].second+1);
                    ans.push_back(vec[k].second+1);
                    break;
                }else if(vec[j].first+vec[k].first<newTarget){
                    j++;
                }else{
                    k--;
                }
            }
        }
        if(ans.size()!=0){
            break;
        }
    }
    if(ans.size()==0){
        cout<<"IMPOSSIBLE";
    }else{

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}