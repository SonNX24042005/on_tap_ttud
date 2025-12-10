#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a;

int max_sub(int l,int r){
    if(l==r)return a[l];
    int m=(l+r)/2;
    int ml=max_sub(l,m);
    int mr=max_sub(m+1,r);
    int mwl=a[m],suml=0;
    for(int j=m;j>=l;j--){
        suml+=a[j];
        mwl=max(suml,mwl);
    }
    int mwr=a[m+1],sumr=0;
    for(int j=m+1;j<=r;j++){
        sumr+=a[j];
        mwr=max(sumr,mwr);
    }
    int mw=mwl+mwr;
    // cout<<l<<' '<<r<<endl;
    // cout<<ml<<' '<<mw<<' '<<mr<<endl;
    return max(ml,max(mw,mr));


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<max_sub(1,n);
    
}