#include<bits/stdc++.h>
using namespace std;
int T;
int n,c;
int d_max;
vector<int>x;
bool check(int d){
    int cnt=1;
    int s=x[0];
    for(int i=1;i<n;i++){
        if(x[i]>=s+d)
        {
            cnt++;
            s=x[i];
        }
    }
    if(cnt>=c)return true;
    return false;
}
void find_d_max(int l,int r){
    // cout<<l<<' '<<r<<' ';
    if(l==r)
    {
        if(check(r)==true){
            d_max=r;
        }
        return;
    }
    int m=(r+l)/2;
    // cout<<m<<endl;
    if(check(m)==true){
        d_max=m;
        find_d_max(m+1,r);
    }else{
        find_d_max(l,m-1);
    }
    
}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>n>>c;
        x.resize(n);
        for(int i=0;i<n;i++){
            cin>>x[i];        }
        sort(x.begin(),x.end());
        // for(int i=0;i<n;i++){
        //     cout<<x[i]<<' ';
        // }
        // cout<<endl;
        int l=0;
        int r=x.back()-x.front();
        find_d_max(l,r);
        cout<<d_max<<endl;
    }
}