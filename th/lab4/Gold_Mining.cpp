#include<bits/stdc++.h>
using namespace std;
int n,l1,l2,ans=0;
vector<int>a,d;
void run(){
    for(int i=l1+1;i<=n;i++){
        for(int j=l1;j<=l2;j++){
            if(i>j){
                d[i]=max(d[i],d[i-j]+a[i]);
                ans=max(d[i],ans);
            }
        }
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