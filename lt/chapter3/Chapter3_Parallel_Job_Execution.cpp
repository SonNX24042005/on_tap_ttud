#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
priority_queue<int>d;
void run(){
    for(int i=0;i<n;i++){
        ans=max(ans,d.top()+i);
        d.pop();
    }
}
int main(){
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        d.push(tmp);
    }
    run();
    cout<<ans;
}