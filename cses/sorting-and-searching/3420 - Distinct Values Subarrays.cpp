#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> vec(n);
    map<int,int> mp;

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    long long ans = 0;
    int l = 0;

    for(int i = 0; i < n; i++){
        mp[vec[i]]++;

        while(mp[vec[i]] > 1){
            mp[vec[l]]--;
            l++;
        }

        ans += (i - l + 1);
    }

    cout << ans;
    return 0;
}