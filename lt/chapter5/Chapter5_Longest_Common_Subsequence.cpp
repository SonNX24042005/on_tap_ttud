#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>x;
vector<int>y;
vector<vector<int>>xy;
void run(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            xy[i][j]=max(xy[i][j-1],xy[i-1][j]);
            if(x[i]==y[j]){
                xy[i][j]=max(xy[i][j],xy[i-1][j-1]+1);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    x.resize(n+1);
    y.resize(m+1);
    xy.resize(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=m;i++)cin>>y[i];
    run();
    cout<<xy[n][m];
}