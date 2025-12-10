#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>rc(n+1,vector<int>(m+1,0));
    int tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tmp;
            rc[i][j]=rc[i][j-1]+tmp;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            rc[i][j]+=rc[i-1][j];
        }

    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<rc[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int q;
    cin>>q;
    int r1,c1,r2,c2;
    while (q--)
    {
        cin>>r1>>c1>>r2>>c2;
        int tmp=rc[r2][c2]-rc[r2][c1-1]-(rc[r1-1][c2]-rc[r1-1][c1-1]);
        cout<<tmp<<endl;
    }
    
}