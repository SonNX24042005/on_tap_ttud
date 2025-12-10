#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q,l=0,r=0,ms=-INT_MAX,sum=0;
    vector<int>a(n);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    while(r<n){
        sum+=a[r];
        r++;
        if(sum>q){
            sum-=a[l];
            l++;
        }
        // cout<<sum;
        ms=max(ms,r-l);
    }
    cout<<ms;
}