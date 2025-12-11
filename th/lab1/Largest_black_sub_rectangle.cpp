#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>a;
vector<int>r;
vector<int>l;
stack<int>tmp;
int get_right(int i,int j){
    int tmp=a[i][j];
    while(j<=m){
        if(a[i][j]<tmp)break;
        j++;
    }
    return j-1;
}
int get_left(int i,int j){
    int tmp=a[i][j];
    while(j>=1){
        if(a[i][j]<tmp)break;
        j--;
    }
    return j+1;
}
int get_max_row(int i){
    int ans=0;
    for(int j=1;j<=m;j++){
        // cout<<get_right(i,j)<<' '<<get_left(i,j)<<endl;
        ans=max(ans,a[i][j]*(get_right(i,j)-get_left(i,j)+1));
    }
    return ans;
}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    a.resize(n+1,vector<int>(m+2));
    r.resize(m+2);
    l.resize(m+2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i-1][j]>=1&&a[i][j]!=0)a[i][j]+=a[i-1][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,get_max_row(i));
    }
    cout<<ans;
}