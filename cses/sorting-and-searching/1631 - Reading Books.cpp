#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int noOfBook;
    cin >> noOfBook;

    long long maxT = 0;
    long long sum = 0;

    for (int i = 0; i < noOfBook; i++) {
        long long time;
        cin >> time;
        maxT = max(maxT, time);
        sum += time;
    }

    long long ans = max(sum, 2 * maxT);
    cout << ans << endl;
    return 0;
}