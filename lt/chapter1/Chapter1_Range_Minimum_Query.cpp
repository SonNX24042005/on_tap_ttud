#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
vector<int>a;
vector<int>smt;
void build(int id,int l,int r){
    if(l==r){
        smt[id]=a[r];
    }
    else{

        int ml=(r+l)/2;
        build(id*2,l,ml);
        build(id*2+1,ml+1,r);
        smt[id]=min(smt[id*2],smt[id*2+1]);
    }
}
int query(int id,int l,int r,int u,int v){
    if(v<l || r<u){
        return INT_MAX;
    }
    else if(u<=l&&r<=v){
        return smt[id];
    }
    else{

        int ml=(l+r)/2;
        return min(query(id*2,l,ml,u,v),query(id*2+1,ml+1,r,u,v));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    a.resize(n+1);
    smt.resize(4*n+4);
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    int i,j;
    cin>>m;
    while(m>0){
        cin>>i>>j;
        ans+=query(1,1,n,i+1,j+1);
        m--;
    }
    cout<<ans;
}