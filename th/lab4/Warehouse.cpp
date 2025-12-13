#include<bits/stdc++.h>
using namespace std;
int N,T,D;
int ans=0;
vector<int>a;
vector<int>t;
vector<vector<int>>k;
void run(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=T;j++){
            if(j<t[i])k[i][j]=0;
            else{
                int mxtmp=0;
                for(int l=i-1;l>=1&&(i-l)<=D;l--){
                    mxtmp=max(mxtmp,k[l][j-t[i]]);
                }
                k[i][j]=mxtmp+a[i];
                ans=max(ans,k[i][j]);
            }
        }
    }
}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>N>>T>>D;
    a.resize(N+1);
    t.resize(N+1);
    k.resize(N+1,vector<int>(T+1));
    for(int i=1;i<=N;i++)cin>>a[i];
    for(int i=1;i<=N;i++)cin>>t[i];
    run();
    cout<<ans<<endl;
    // for(auto i:k){
    //     for(auto j:i){
    //         cout<<j<<' ';
    //     }
    //     cout<<endl;
    // }
}