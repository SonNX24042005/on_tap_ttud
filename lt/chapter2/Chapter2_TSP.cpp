#include<bits/stdc++.h>
using namespace std;
int n;
vector <vector<int>> c;
vector <int>check;
vector <int> path;
int phan_tu_chi_phi_nho_nhat=INT_MAX;
int chi_phi_hien_tai=0;
int chi_phi_tot_nhat=INT_MAX;
void Try(int k){
    for(int i=2;i<=n;i++){
        if(check[i]==0){
            check[i]=1;
            chi_phi_hien_tai+=c[path.back()][i];
            path.push_back(i);
            if(k==n){
                chi_phi_hien_tai+=c[i][1];
                chi_phi_tot_nhat=min(chi_phi_hien_tai,chi_phi_tot_nhat);
                chi_phi_hien_tai-=c[i][1];

            }
            else{
                if(phan_tu_chi_phi_nho_nhat*(n-k)+chi_phi_hien_tai<chi_phi_tot_nhat){
                    Try(k+1);

                }
            }
            path.pop_back();
            chi_phi_hien_tai-=c[path.back()][i];
            check[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    c.resize(n+1,vector<int>(n+1));
    check.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            phan_tu_chi_phi_nho_nhat=min(phan_tu_chi_phi_nho_nhat,c[i][j]);

    }
    check[1]=1;
    path.push_back(1);
    Try(2);
    cout<<chi_phi_tot_nhat;

}