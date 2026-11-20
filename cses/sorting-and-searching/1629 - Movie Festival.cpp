#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> movie(n);

    for(int i = 0; i < n; i++){
        int startTime, endTime;
        cin >> startTime >> endTime;
        movie[i] = {startTime, endTime};
    }

    sort(movie.begin(), movie.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    long long ans=0;
    int movieEnd=movie[0].second;
    long long curr=1;
    for(int i=1;i<n;i++){
        if(movie[i].first<movieEnd){
            movieEnd=min(movieEnd,movie[i].second);
        }else if(movie[i].first>=movieEnd){
            curr++;
            movieEnd=movie[i].second;
        }
        ans=max(ans,curr);


    }
    cout<<ans<<endl;

    return 0;
}