#include<bits/stdc++.h>
using namespace std;
int x;
vector<int>u(5,0);
int m[]={100,25,10,5,1};
void run(){
    for(int i=0;i<5;i++){
        while(x>=m[i]){
            // cout<<x;
            x-=m[i];
            u[i]++;//200+75+10+
        }
    }
}
int main(){
    cin>>x;
    run();
    for(int i=4;i>=0;i--){
        cout<<u[i]<<' ';
    }
}