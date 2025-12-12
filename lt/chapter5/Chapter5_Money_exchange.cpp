#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,X;
    cin>>n>>X;
    vector<int>d;
    d.resize(n);
    for(int i=0;i<n;i++)cin>>d[i];
    const int INF=X+1;
    vector<int>dp(X+1,INF);
    dp[0]=0;
    for(auto c:d){
        for(int i=c;i<=X;i++){
            dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    if(dp[X]==INF)cout<<-1;
    else cout<<dp[X];
}