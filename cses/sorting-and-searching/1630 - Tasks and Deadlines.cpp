#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++) {
        int timeReq, deadline;
        cin >> timeReq >> deadline;
        vec[i] = {timeReq, deadline};
    }

    sort(vec.begin(), vec.end());

    long long maxProfit = 0;
    long long time = 0;

    for (int i = 0; i < n; i++) {
        time += vec[i].first;
        maxProfit += vec[i].second - time;
    }

    cout << maxProfit << endl;

    return 0;
}