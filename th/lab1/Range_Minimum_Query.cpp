#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;
vector<int>smt;
void build(int id,int l,int r){
    if(r==l){
        smt[id]=a[r];
    }
    else{
        build(id*2,l,(l+r)/2);
        build(id*2+1,(l+r)/2+1,r);
        smt[id]=min(smt[id*2],smt[id*2+1]);
    }
}
int query(int id,int l,int r,int u,int v){
    if(v<l||r<u)return INT_MAX;
    else if(u<=l&&r<=v)return smt[id];
    else{
        return min(query(id*2,l,(l+r)/2,u,v),query(id*2+1,(l+r)/2+1,r,u,v));
    }
}
int main(){
    cin>>n;
    a.resize(n+1);
    smt.resize(4*n+4);
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    cin>>m;
    int i,j;
    int ans=0;
    while(m--){
        cin>>i>>j;
        ans+=query(1,1,n,i+1,j+1);
    }
    cout<<ans;
}
