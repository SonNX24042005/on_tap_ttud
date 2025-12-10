#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> dp;
int ans=0;
int tg=1;
priority_queue<int,vector<int>,greater<int>>pq;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}

void run(){
    for (auto &j : dp) {
        pq.push(j.second);
        if(pq.size()>j.first){
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    dp.resize(n);
    for(int i=0;i<n;i++){
        cin>>dp[i].first>>dp[i].second;
    }
    sort(dp.begin(),dp.end(),cmp);
    run();
    cout<<ans;
}
