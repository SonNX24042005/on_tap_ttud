#include<bits/stdc++.h>
using namespace std;
int n;
double cost=0;
priority_queue<int,vector<int>,greater<int>>pq;
int main(){
    cin>>n;
    int tmp;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>tmp;
        pq.push(tmp);
    }
    while(pq.size()>1){
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        cost=cost+(a+b)*0.05;
        pq.push(a+b);
    }
    cout<<int(cost);
}