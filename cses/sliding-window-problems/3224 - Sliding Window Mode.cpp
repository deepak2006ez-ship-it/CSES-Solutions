#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

struct Compare {
    bool operator()(const pair<int,int>& a,
                    const pair<int,int>& b) const {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int main() {
    

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    set<pair<int,int>, Compare> s;
    unordered_map<int,int> mp;

    // Build the first window
    for(int i = 0; i < k; i++) {
        if(mp[vec[i]] > 0) {
            s.erase({mp[vec[i]], vec[i]});
        }

        mp[vec[i]]++;
        s.insert({mp[vec[i]], vec[i]});
    }

    cout << s.begin()->second << " ";

    // Slide the window
    int st = 0;

    for(int i = k; i < n; i++) {

        // Remove outgoing element
        int outgoing = vec[st++];

        s.erase({mp[outgoing], outgoing});
        mp[outgoing]--;

        if(mp[outgoing] > 0) {
            s.insert({mp[outgoing], outgoing});
        }

        // Add incoming element
        int incoming = vec[i];

        if(mp[incoming] > 0) {
            s.erase({mp[incoming], incoming});
        }

        mp[incoming]++;
        s.insert({mp[incoming], incoming});

        cout << s.begin()->second << " ";
    }

    return 0;
}