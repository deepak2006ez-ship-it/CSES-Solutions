#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int noOfMovie,noOfViewer;
    cin>>noOfMovie>>noOfViewer;
    vector<pair<int,int>>vec(noOfMovie);
    for(int i=0;i<noOfMovie;i++){
        int start,end;
        cin>>start>>end;
        vec[i]={start,end};
    }
    sort(vec.begin(),vec.end());
    
    multiset<int>s;
    int currViewer=1;
    int totalMovie=1;
    s.insert(vec[0].second);
    for(int i=1;i<noOfMovie;i++){
        int movieStart=vec[i].first;
        auto it=s.upper_bound(movieStart);
        if (it != s.begin()) {
            --it;
        }
        if(*it<=movieStart){
            totalMovie++;
            s.erase(it);
            s.insert(vec[i].second);

        }else{
            if(currViewer<noOfViewer){
                s.insert(vec[i].second);
                currViewer++;
                 totalMovie++;


            }else{
                auto it = prev(s.end());
                if(*it>vec[i].second){

                    s.erase(it);
                    s.insert(vec[i].second);
                }

            }


        }
        
    }
    cout<<totalMovie<<endl;
    return 0;
}