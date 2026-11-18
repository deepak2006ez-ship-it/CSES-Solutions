#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> requiredApp(n);
    vector<int> availableApp(m);

    for (int i = 0; i < n; i++) {
        cin >> requiredApp[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> availableApp[i];
    }

    sort(requiredApp.begin(), requiredApp.end());
    sort(availableApp.begin(), availableApp.end());

    int j = 0, i = 0;
    long long allocatedApp = 0;

    while (j < n && i < m) {
        long long a = (long long)requiredApp[j] - k;
        long long b = (long long)requiredApp[j] + k;

        if (availableApp[i] >= a && availableApp[i] <= b) {
            allocatedApp++;
            j++;
            i++;
        }
        else if (availableApp[i] < a) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << allocatedApp << '\n';

    return 0;
}