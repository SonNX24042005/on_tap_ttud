#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> path;
void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << path[i];
    }
    cout << endl;
}
bool check(int i,int k){
    if(path[k-1]==1 && i==1)return false;
    return true;
}
void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        if (check(i,k))
        {
            path[k] = i;
            // cout<<"1";
            if (k == n)
            {
                // cout<<"@";
                solution();
            }
            else
            {
                Try(k + 1);
            }
        }
    }
}
int main()
{
    cin >> n;
    path.resize(n + 1);
    Try(1);
}