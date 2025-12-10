#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int l=0,r=n-1,cnt=0;
    while(l<r){
        if(a[l]+a[r]==q){
            cnt++;
            l++;
            r--;
        }
        else if(a[l]+a[r]<q){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<cnt;

}