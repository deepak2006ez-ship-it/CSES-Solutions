#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int main() {
    int noOfMovie, noOfViewer;
    cin >> noOfMovie >> noOfViewer;

    vector<pair<int,int>> vec(noOfMovie);

    for(int i = 0; i < noOfMovie; i++) {
        int startT, endT;
        cin >> startT >> endT;
        vec[i] = {endT, startT};
    }

    sort(vec.begin(), vec.end());

    multiset<int> s;

    for(int i = 0; i < noOfViewer; i++) {
        s.insert(0);
    }

    int ans = 0;

    for(auto [endT, startT] : vec) {
        auto it = s.upper_bound(startT);

        if(it == s.begin()) {
            continue;
        }

        --it;

        ans++;
        s.erase(it);
        s.insert(endT);
    }

    cout << ans << '\n';

    return 0;
}