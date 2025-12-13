#include<bits/stdc++.h>
using namespace std;
int n,k1,k2;
const int q=1000000007;
vector<vector<int>>dp;
void run(){
    for(int i=1;i<=n;i++){
        for(int j=k1;j<=k2;j++ ){
            if(i>=j)dp[i][1]=(dp[i][1]+dp[i-j][0])%q;
        }
        dp[i][0]=dp[i-1][1];
    }
}
int main(){
    cin>>n>>k1>>k2;
    dp.resize(n+1,vector<int>(2));
    dp[0][0]=1;
    dp[0][1]=1;
    run();
    cout<<(dp[n][0]+dp[n][1])%q;
}