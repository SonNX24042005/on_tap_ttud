#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int load;
int cnt=0;
int d_min=INT_MAX;
vector<int> d;
vector<int>vd;
vector<int>vx;
vector<int>vs;

bool check(int x,int i){
    if(vd[i]==1)return false;
    if(vx[x]>=vd[i]&&vs[x]>vs[x-1])return true;
    // if(vx[x]>=vd[i])return true;
    return false;
}
void Try(int x){
    for(int i=1;i<=n;i++){
        if(vs[x]==0)vs[x]=i;
        if(check(x,i)){
            vd[i]=1;
            vx[x]-=d[i];
            load--;
            if(!load && x==k){
                cnt++;
            }
            else{
                if(x+1<=k)Try(x+1);
                if(vx[x]>=d_min&&load>=(k-x))Try(x);
            }
            load++;
            vx[x]+=d[i];
            vd[i]=0;
        }
        if(vx[x]==q)vs[x]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>q;
    load=n;
    d.resize(n+1);
    vd.resize(n+1);
    vx.resize(k+1,q);
    vs.resize(k+1);
    for (int i=1;i<=n;i++){
        cin>>d[i];
        d_min=min(d_min,d[i]);
    }
    Try(1);
    cout<<cnt;
}