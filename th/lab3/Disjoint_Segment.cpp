#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>>ab;
bool cmp(pair<int,int>a, pair<int,int>b){
    return a.second<b.second;
}
int main(){
    freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>n;
    int a,b;
    ab.resize(n);
    for(int i=0;i<n;i++){
        cin>>ab[i].first>>ab[i].second;
    }
    sort(ab.begin(),ab.end(),cmp);
    int e=-1;
    int ans=0;
    for(int i=0;i<n;i++){
        if(e<ab[i].first){
            ans+=1;
            e=ab[i].second;
        }
    }
    cout<<ans;
}
