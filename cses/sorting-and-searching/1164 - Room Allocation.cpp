#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<climits>
using namespace std;

int main(){
 

    int n;
    cin>>n;
    vector<pair<pair<int,int>, int>> vec(n);   // {{arrival, departure}, index}
    for(int i=0;i<n;i++){
        int arrival,dept;
        cin>>arrival>>dept;
        vec[i]={{arrival,dept},i};
    }
    sort(vec.begin(),vec.end());

    set<pair<pair<int,int>,int>> s;   // {{departure, room}, index}
    vector<int> ans(n);
    int roomNo=0;

    for(int i=0;i<n;i++){
        int arrival = vec[i].first.first;
        int dept    = vec[i].first.second;
        int idx     = vec[i].second;

        auto it = s.lower_bound({{arrival, INT_MIN}, INT_MIN});
        if(it != s.begin()){
            --it;
            int room = it->first.second;   // read before erase
            s.erase(it);
            s.insert({{dept, room}, idx});
            ans[idx] = room;
        } else {
            ++roomNo;
            s.insert({{dept, roomNo}, idx});
            ans[idx] = roomNo;
        }
    }

    cout<<roomNo<<"\n";
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}