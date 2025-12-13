#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
vector<int>tmp;
int ans=0;
const int q=1000000007;
void ms(int l,int r){
    
    if(l==r)return;
    int m=(l+r)/2;
    ms(l,m);
    ms(m+1,r);
    int i=l,j=m+1;
    int cnt=l;
    while(i<=m||j<=r){
        if(i<=m&&(j>r||a[i]<=a[j])){  // Sửa j<r thành j>r
            tmp[cnt++]=a[i++];
        }
        else{
            ans=(ans+(m-i+1)%q)%q;  // Sửa m-i thành m-i+1
            tmp[cnt++]=a[j++];
        }
    }
    // Copy kết quả từ tmp về a (bắt buộc!)
    for(int k=l;k<=r;k++){
        a[k]=tmp[k];
    }
}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>n;
    a.resize(n+1);
    tmp.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    ms(1,n);
    cout<<ans;

}