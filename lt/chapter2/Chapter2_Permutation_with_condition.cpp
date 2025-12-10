#include<bits/stdc++.h>
using namespace std;
vector <int> check;
int n;
int dem=0;

void Try(int k){
    for(int i=1;i<=n;i++){
        if (check[i]==0){
            check[i]=1;
            if (i%k==0||k%i==0){
                if (k==n){
                    dem++;
                }
                else{
                    Try(k+1);
                }
            }
            check[i]=0;

        }
    }
}
int main(){
    cin>>n;
    check.resize(n+1);
    Try(1);
    cout<<dem;

}