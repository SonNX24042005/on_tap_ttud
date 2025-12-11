#include<bits/stdc++.h>
using namespace std;
int n,B;
vector<int>dp;
int main(){
    cin>>n>>B;
    dp.resize(B+1,0);
    int w,v;
    for(int i=0;i<n;i++){
        cin>>w>>v;
        for(int cap=B;cap>=w;cap--){
            dp[cap]=max(dp[cap],dp[cap-w]+v);
        }
    }
    auto it=max_element(dp.begin(),dp.end());
    cout<<*it;
}