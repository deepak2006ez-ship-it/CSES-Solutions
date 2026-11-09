#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
    int n;
    cin >> n;

    int windowSize;
    cin >> windowSize;
    deque<int> dq;//storing index not value
    vector<int> vec(n);
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    
    long long ans = 0;
    int ans1=0;

    vec[0] = x;

    for(int i = 1; i < n; i++){
        vec[i] = ((1LL * a * vec[i-1]) + b) % c;
    }

    for(int i=0;i<windowSize;i++){
        if(dq.empty() || vec[i]>=vec[dq.back()]){
            dq.push_back(i);
        }else{

            while(!dq.empty() && vec[i]<vec[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    for(int i=windowSize;i<n;i++){
        ans1=ans1^vec[dq.front()];
        
        while(!dq.empty()&&vec[i]<vec[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        int startIdx=i-windowSize;
        while(!dq.empty()&&dq.front()<=startIdx){
            dq.pop_front();
        }
    }
            ans1=ans1^vec[dq.front()];

   
    cout << ans1;

    return 0;
}