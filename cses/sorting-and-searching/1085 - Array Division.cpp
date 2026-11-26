#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long isValidate(vector<long long>& vec, long long ans, int k) {
    int count = 1;
    long long curr = 0;

    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > ans) {
            return -1;
        }
        else if(curr + vec[i] <= ans) {
            curr += vec[i];
        }
        else {
            curr = vec[i];
            count++;
        }
    }

    if(count > k) {
        return -1;
    }

    return 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    long long st = 0, end = 0;
    vector<long long> vec(n);

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
        st = max(st, vec[i]);
        end += vec[i];
    }

    long long ans = LLONG_MAX;

    while(st <= end) {
        long long mid = st + (end - st) / 2;

        long long searchSpace = isValidate(vec, mid, k);

        if(searchSpace != -1) {
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