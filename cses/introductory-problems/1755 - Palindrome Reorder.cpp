#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n=s.size();
    vector<int>freq(26,0);
    for(int i=0;i<n;i++){
        freq[s[i]-'A']++;
    }
    int noOfOddFreq=0;
    bool isValidSoln=true;
    for(int i=0;i<26;i++){
        if(freq[i]%2!=0){
            noOfOddFreq++;
            if(noOfOddFreq==2){
                isValidSoln=false;
                break;
            }
        }
    }
    vector<char>ans(n);
    if(!isValidSoln ||((noOfOddFreq==1)&&(n%2==0)) ){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        int j=0,k=n-1;
        for(int i=0;i<26;i++){
            while(freq[i]!=0){
                char c=i+'A';
                if(freq[i]%2==0){
                    ans[j++]=c;
                    ans[k--]=c;


                    freq[i]-=2;
    
                }else{
                    ans[n/2]=c;
                    freq[i]-=1;

                }

            }
        }
        for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<endl;
    }

    



    

  
    return 0;
}