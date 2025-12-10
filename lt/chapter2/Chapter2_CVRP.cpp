#include <bits/stdc++.h>
using namespace std;
int n, k, q;
vector<int> d;
vector<vector<int>> c;
// int c_min = INT_MAX;
// int c1_min = INT_MAX;
vector<int>ci_min;
vector<int> v;
vector<int> vx;
int cost = 0;
int cost_min = INT_MAX;
int d_min = INT_MAX;
vector<int> path;
int vst;
int cnt=0;
vector<int>sk;

bool check(int i, int x)
{
    if (v[i] == 1)
        return false;
    if (vx[x] >= d[i] && sk[x-1]<sk[x])
        return true;
    return false;
}
int lower_bound(){
    int tmp=0;
    for(int i=0;i<=n;i++){
        if(v[i]==0)tmp+=ci_min[i];
    }
    return tmp;
}
void Try(int x)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (cost+lower_bound()>cost_min)return;

    for (int i = 1; i <= n; i++)
    {
        if(sk[x]==0)sk[x]=i;
        if (check(i, x))
        {
            v[i] = 1;
            vst--;
            cost += c[path.back()][i];
            path.push_back(i);
            vx[x] -= d[i];
            if (!vst)
            {
                cost_min = min(cost + c[i][0], cost_min);
                cnt++;
            }
            else
            {
                path.push_back(0);
                cost += c[i][0];
                if (x + 1 <= k)
                {
                    Try(x + 1);
                }
                cost -= c[i][0];
                path.pop_back();
                if (vx[x] >= d_min)
                {
                    Try(x);
                }
            }
            vx[x] += d[i];
            path.pop_back();
            cost -= c[path.back()][i];
            vst++;
            v[i] = 0;
        }
        if(vx[x]==q)sk[x]=0;
    }
}
int main()
{
    cin >> n >> k >> q;
    vst = n;
    d.resize(n + 1);
    c.resize(n + 1, vector<int>(n + 1));
    v.resize(n + 1);
    vx.resize(k + 1, q);
    path.resize(1);
    ci_min.resize(n+1,INT_MAX);
    sk.resize(k+1,0);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        d_min = min(d_min, d[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            ci_min[j]=min(ci_min[j],c[i][j]);
        }
    }
    Try(1);
    cout << cost_min<<endl<<cnt;
}