#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdlib>
using namespace std;
void subsetBuilder(vector<long long>&vec,long long totalSum,long long group1Sum,int idx,long long &ans){
    if(idx>=vec.size()){
        long long group2Sum=totalSum-group1Sum;
        ans=min(ans,abs(group1Sum-group2Sum));

        return;
    }
    group1Sum+=vec[idx];
    subsetBuilder(vec,totalSum,group1Sum,idx+1,ans);
    group1Sum-=vec[idx];
    subsetBuilder(vec,totalSum,group1Sum,idx+1,ans);
}
int main(){
    int n;
    cin>>n;
    vector<long long>vec(n);
    long long totalWeightSum=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        totalWeightSum+=vec[i];
    }
    long long ans = LLONG_MAX;
    subsetBuilder(vec,totalWeightSum,0,0,ans);
    cout<<ans<<endl;
    
    return 0;
}