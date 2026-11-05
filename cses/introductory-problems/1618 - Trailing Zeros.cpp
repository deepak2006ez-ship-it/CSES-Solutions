#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int factorOf5=0;
    int multipleOf5=5;
    while(multipleOf5<=n){
        factorOf5+=n/multipleOf5;
        multipleOf5*=5;

    }
    cout<<factorOf5;
    return 0;
}