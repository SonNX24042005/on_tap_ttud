#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int ans=INT_MAX;
int max_cur=0;
vector<int>vm;
vector<vector<int>>mi;//để lưu số môn 1 giảng viên có thể dạy
vector<vector<int>>ki;//để lưu ràng buộc giữa các môn
vector<vector<int>>umi;//để lưu số môn 1 giảng viên đang dạy

bool check(int s,int i){
    int tmp=0;
    for(int j=1;j<=n;j++)if(mi[i][j]==s)tmp=1;
    if(tmp==0)return false;
    if(mi[i][0]==vm[i])return false;
    for(int j=1;j<=n;j++){
        if(ki[s][umi[i][j]]==1)return false;
    }
    return true;

}
void Try(int s){//s đại diện cho môn thứ s
    for(int i=0;i<m;i++){
        if(check(s,i)){
            vm[i]+=1;
            umi[i][vm[i]]=s;
            int old_max_cur=max_cur;
            max_cur=max(vm[i],max_cur);
            if(s==n){
                ans=min(ans,max_cur);
            }
            else{
                if(max_cur<ans)Try(s+1);
            }
            umi[i][vm[i]]=0;
            vm[i]-=1;
            max_cur=old_max_cur;

        }
    }
}
int main(){
    // freopen("d:\\DT\\Learn\\20251\\ThuatToanUngDung\\on_tap_ttud\\input.txt","r",stdin);
    cin>>m>>n;
    mi.resize(m,vector<int>(n+1));
    ki.resize(n+1,vector<int>(n+1));
    vm.resize(m);
    umi.resize(m,vector<int>(n+1));

    for(int i=0;i<m;i++){
        cin>>mi[i][0];
        for(int j=1;j<=mi[i][0];j++){
            cin>>mi[i][j];
        }
    }
    int i,j;
    cin>>k;
    for(int a=0;a<k;a++){
        cin>>i>>j;
        ki[i][j]=1;
        ki[j][i]=1;
    }
    Try(1);
    cout<<ans;
}