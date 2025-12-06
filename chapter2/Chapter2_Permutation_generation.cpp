#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> check;
vector <int> sol;
void print_sol(){
    for(auto it=sol.begin();(it+1)!=sol.end();++it){
        cout<<*(it+1)<<' ';
    }
    cout<<'\n';
}
void Try(int k){
    for(int i=1;i<=n;i++){
        if (check[i]==0){
            check[i]=1;
            sol[k]=i;
            if(k==n){
                print_sol();
            }
            else{
                Try(k+1);
            }
            check[i]=0;        
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    check.resize(n+1);
    sol.resize(n+1);
    Try(1);
}