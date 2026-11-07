#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int windowSize;
    cin >> windowSize;

    vector<int> vec(n);

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    long long currWindowXor = 0;
    long long ans = 0;

    vec[0] = x;

    for(int i = 1; i < n; i++){
        vec[i] = ((1LL * a * vec[i-1]) + b) % c;
    }

    for(int i = 0; i < windowSize; i++){
        currWindowXor ^= vec[i];
    }

    ans = currWindowXor;

    int st = 0;

    for(int i = windowSize; i < n; i++){
        currWindowXor ^= vec[st++];
        currWindowXor ^= vec[i];

        ans = ans ^ currWindowXor;
    }

    cout << ans;

    return 0;
}