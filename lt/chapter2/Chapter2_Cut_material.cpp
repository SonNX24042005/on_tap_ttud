#include <bits/stdc++.h>
using namespace std;
int h, w;
int n;
vector<pair<int, int>> ni;
vector<vector<int>> hw;
int ans = 0;
bool check(int i, int j, int nih, int niw){
    if (i + nih - 1 > h || j + niw - 1 > w){
        // cout<<'c';
        return false;
    }
    for (int c = i; c < i + nih; c++){
        for (int r = j; r < j + niw; r++){
            if (hw[c][r] == 1)return false;
        }
    }
    return true;
}
void mark(int i, int j, int nih, int niw, int state){
    for (int c = i; c < i + nih; c++){
        for (int r = j; r < j + niw; r++){
            hw[c][r] = state;
        }
    }
}

void Try(int k){
    int nih = ni[k].first;
    int niw = ni[k].second;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if (ans == 1)return;
            if (check(i, j, nih, niw)){
                mark(i, j, nih, niw, 1);
                if (k == n){
                    ans = 1;
                    return;
                }
                else{
                    Try(k + 1);
                }
                mark(i, j, nih, niw, 0);
            }
            if (nih != niw){
                if (check(i, j, niw, nih)){
                    // cout<<"@";
                    mark(i, j, niw, nih, 1);
                    if (k == n){
                        ans = 1;
                        return;
                    }
                    else{
                        Try(k + 1);
                    }
                    mark(i, j, niw, nih, 0);
                }
            }
        }
    }
}

int main()
{
    cin >> h >> w;
    cin >> n;
    ni.resize(n + 4);
    int total=0;
    hw.resize(h + 4, vector<int>(w + 4));
    for (int i = 1; i <= n; i++){
        cin >> ni[i].first >> ni[i].second;
        total+=ni[i].first* ni[i].second;
    }
    if(total>h*w){
        cout<<0;
    }
    else{
        Try(1);
        cout << ans;  
    }

}