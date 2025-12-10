#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int>a;
vector<int>smt;
void build(int id,int l,int r){
    if(l==r)smt[id]=a[l];
    else{
        build(id*2,l,(l+r)/2);
        build(id*2+1,(l+r)/2+1,r);
        smt[id]=smt[id*2]+smt[id*2+1];
    }
}
int query(int id,int l,int r,int u,int v){
    if(v<l||r<u)return 0;
    else if(u<=l&&r<=v)return smt[id];
    else{
        return query(id*2,l,(l+r)/2,u,v)+query(id*2+1,(l+r)/2+1,r,u,v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);

    cin>>n;
    a.resize(n+1);
    smt.resize(4*n+4);
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    // for(int i=1;i<=n;i++)cout<<smt[i];
    cin>>q;
    int i,j;
    while(q--){
        cin>>i>>j;
        cout<<query(1,1,n,i,j)<<endl;

    }
}