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

    long long currWindowSum = 0;
    long long ans = 0;

    vec[0] = x;

    for(int i = 1; i < n; i++){
        vec[i] = ((1LL * a * vec[i-1]) + b) % c;
    }

    for(int i = 0; i < windowSize; i++){
        currWindowSum += vec[i];
    }

    ans = currWindowSum;

    int st = 0;

    for(int i = windowSize; i < n; i++){
        currWindowSum -= vec[st++];
        currWindowSum += vec[i];

        ans = ans ^ currWindowSum;
    }

    cout << ans;

    return 0;
}