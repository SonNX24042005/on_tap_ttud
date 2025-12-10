#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    map<int,int>a;
    map<int,int>b;
    while(t--){
        int tmp,ans=0;
        cin>>n>>m;
        a.clear();
        b.clear();
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(a.find(tmp)==a.end())a[tmp]=1;
            else a[tmp]++;
        }
        for(int i=0;i<m;i++){
            cin>>tmp;
            if(b.find(tmp)==b.end())b[tmp]=1;
            else b[tmp]++;
        }
        for(auto i:a){
            ans=ans+2*min(i.second,b[i.first]);
        }
        cout<<(n+m-ans)<<endl;
    }
}