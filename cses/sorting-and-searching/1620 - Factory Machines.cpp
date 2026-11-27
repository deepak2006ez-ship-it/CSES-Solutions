#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int validState(vector<long long>& vec, long long possibleTime, long long productCount) {
    long long productMade = 0;

    for (int i = 0; i < vec.size(); i++) {
        productMade += possibleTime / vec[i];

        if (productMade >= productCount) {
            return 1;
        }
    }

    return -1;
}

int main() {
    int machineCount;
    long long productCount;
    cin >> machineCount >> productCount;

    long long st = LLONG_MAX;
    long long end = LLONG_MIN;

    vector<long long> vec(machineCount);

    for (int i = 0; i < machineCount; i++) {
        cin >> vec[i];
        st = min(st, vec[i]);
        
    }
    end=st;

    end *= productCount;

    long long ans = LLONG_MAX;

    while (st <= end) {
        long long mid = st + (end - st) / 2;

        if (validState(vec, mid, productCount) == 1) {
            ans = min(ans, mid);
            end = mid - 1;
        } 
        else {
            st = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}