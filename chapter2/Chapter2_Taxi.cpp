#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>c;
int c_min=INT_MAX;
vector<int>v;
vector<int>path;
int load_max=1;
int load=0;
int cost=0;
int cost_min=INT_MAX;
bool check(int i){
    if(v[i]==1)return false;
    if(i<=n){
        return (load<load_max);
    }
    else{
        return(v[i-n]==1);
    }
}
void Try(int k){
    for(int i=1;i<=2*n;i++){
        if(check(i)){

            v[i]=1;
            path[k]=i;
            if(i<=n)load++;
            else load--;
            cost+=c[path[k-1]][i];
            if(k==2*n){
                cost_min=min(cost_min,cost+c[i][0]);
                // cout<<cost_min;
            }
            else{
                if(c_min*(2*n-k+1)+cost<cost_min){
                     Try(k+1);
                }
            }
            cost-=c[path[k-1]][i];
            if(i<=n)load--;
            else load++;
            v[i]=0;

        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    c.resize(2*n+1,vector<int>(2*n+1));
    v.resize(2*n+1,0);
    path.resize(2*n+1,0);
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>c[i][j];
            if(i!=j){
                c_min=min(c_min,c[i][j]);
            }
        }
    }
    Try(1);
    cout<<cost_min;
}