#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    long long a=0,b=0;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        long long smaller = min(a,b);
        long long larger  = max(a,b);
        long long diff    = larger - smaller;
        if((a+b)%3==0 && diff<=smaller){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}