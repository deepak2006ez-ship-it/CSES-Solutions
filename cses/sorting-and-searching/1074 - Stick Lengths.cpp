#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int median = vec[n/2];

    long long ans = 0;

    for(int i = 0; i < n; i++){
        ans += abs(vec[i] - median);
    }

    cout << ans;

    return 0;
}