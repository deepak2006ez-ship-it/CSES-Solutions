#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;
int main(){
    set<pair<int,int>>s;
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(!s.empty()){
            auto it = s.upper_bound({vec[i], INT_MAX});
            if(it!=s.end() && it->first>vec[i]){
                s.erase({it->first,it->second});
                s.insert({vec[i],i});
                

            }else{
                s.insert({vec[i],i});

            }

        }else{

            s.insert({vec[i],i});
        }
    }
    cout<<s.size();

    return 0;
}