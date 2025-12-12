#include<bits/stdc++.h>
using namespace std;
int n,load_max;
int load=0;
int cost=0;
int cost_min=INT_MAX;
int c_min=INT_MAX;
vector<int>v;
vector<vector<int>>c;
vector<int>path;
bool check(int i){
    if(v[i]==1)return false;
    if(i<=n){
        if(load<load_max)return true;
    }
    else{
        if(v[i-n]==1)return true;
    }
    return false;
}
void Try(int k){
    for(int i=1;i<=2*n;i++){
        if(check(i)){
            v[i]=1;
            path[k]=i;
            cost+=c[path[k-1]][i];
            if(i<=n)load++;
            else load--;
            // cout<<i<<endl;
            if(k==2*n){
                cost_min=min(cost_min,cost+c[i][0]);
            }
            else{
                // Try(k+1);
                if(cost+(2*n-k)*c_min<cost_min)Try(k+1);
            }
            if(i<=n)load--;
            else load++;
            cost-=c[path[k-1]][i];
            v[i]=0;

        }
    }
}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>n>>load_max;
    c.resize(2*n+2,vector<int>(2*n+2));
    v.resize(2*n+2);
    path.resize(2*n+2);

    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>c[i][j];
            if(i!=j)c_min=min(c_min,c[i][j]);
        }
    }
    // cout<<c_min<<endl;
    Try(1);
    cout<<cost_min;
}