#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int len,noOfTrafficLight;
    cin>>len>>noOfTrafficLight;
    vector<int>vec(noOfTrafficLight);
    for(int i=0;i<noOfTrafficLight;i++){
        cin>>vec[i];
    }
    multiset<int>allLoc;
    multiset<int>possAns;
    allLoc.insert(0);
    allLoc.insert(len);
    possAns.insert(len);
    for(int i=0;i<noOfTrafficLight;i++){
        auto upB = allLoc.upper_bound(vec[i]);
        auto lowB = prev(upB);
        allLoc.insert(vec[i]);
        int  rightV=*upB-vec[i];
        int leftV=vec[i]-*lowB;
        auto it=possAns.find(rightV+leftV);
        possAns.erase(it);
        possAns.insert(leftV);
        possAns.insert(rightV);
        cout<<*prev(possAns.end())<<" ";
    }
    cout<<endl;

    return 0;
}