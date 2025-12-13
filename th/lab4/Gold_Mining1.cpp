#include<bits/stdc++.h>
using namespace std;
int n,l1,l2,ans=0;
vector<int>a,d;
priority_queue<pair<int,int>>pq;
void run(){
    for(int i=l1+1;i<=n;i++){
        pq.push({d[i-l1],i-l1});
        while(!pq.empty()&&pq.top().second<i-l2)pq.pop();
        if(!pq.empty())d[i]=a[i]+pq.top().first;
        else d[i]=a[i];
        ans=max(ans,d[i]);
    }

}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>n>>l1>>l2;
    a.resize(n+1);
    d.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=l1;i++){
        d[i]=a[i];
        ans=max(ans,d[i]);
        // cout<<d[i]<<' ';
    }
    run();
    cout<<ans;
}