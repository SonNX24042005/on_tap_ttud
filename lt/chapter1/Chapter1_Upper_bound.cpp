#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    string cmd;
    int k;
    while(1){
        cin>>cmd;
        if(cmd=="#")break;
        cin>>k;
        auto it=upper_bound(a.begin(),a.end(),k);
        if(it!=a.end()){
            cout<<*it;
        }else{
            cout<<-1;
        }
        cout<<endl;
    }
}