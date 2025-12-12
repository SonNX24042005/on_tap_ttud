#include<bits/stdc++.h>
using namespace std;
int n,m,suma=0;
vector<int>a;
vector<int>w;
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>n>>m;
    a.resize(n);
    w.resize(m+1);
    w[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        suma+=a[i];
    }
    m-=suma;
    for(auto item:a){
        for(int i=item;i<=m;i++){
            w[i]=w[i]+w[i-item];
        }
    }
    // for(int i=1;i<=m;i++){
    //     cout<<w[i]<<' ';
    // }
    cout<<w[m];
}