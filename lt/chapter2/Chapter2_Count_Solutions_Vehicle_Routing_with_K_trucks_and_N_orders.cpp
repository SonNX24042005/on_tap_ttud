#include<bits/stdc++.h>
using namespace std;
int n,k;
const int q=100000;
int c[105][105]={0};
void pc(){
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(i>=j){
                if(i==j || i==0){
                    c[i][j]=1;
                }
                else if(i>j){
                    c[i][j]=(c[i-1][j]+c[i-1][j-1])%q;
                }
            }
        }
    }
}
int main(){
    cin>>n>>k;
    pc();
    int tmp=1;
    for(int i=k+1;i<=n;i++){
        tmp=tmp*i%q;
    }
    cout<<endl<<tmp*c[n-1][k-1]%q;
}