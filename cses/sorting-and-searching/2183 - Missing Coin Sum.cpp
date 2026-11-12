#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
     long long x=0;//represent sum tll curr position
    for(int i=0;i<n;i++){
        if(vec[i]<=x+1){
            x+=vec[i];
        }else{
            
            break;
        }
    }
    cout<<x+1;
    return 0;
}