#include<bits/stdc++.h>
#define mx 1000007
using namespace std;
pair<int,int> ara[mx], tree[4 * mx];
long long dp[mx];
void build(int node,int l,int r)
{
    if(l == r)
    {
        tree[node] = ara[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid); build(2 * node + 1, mid + 1, r);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
pair<int,int> query(int node,int l,int r,int x,int y)
{
    if(r < x || l > y || l > r) return {0,0};
    if(l >= x && r <= y)
    {
        return tree[node];
    }
    int mid = (l + r) / 2;
    return max(query(2 * node, l, mid, x, y), query(2 * node + 1, mid + 1, r, x, y));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i<n; i++)
    {
        cin >> ara[i].first;
        ara[i].second = i;
    }
    build(1,1,n);
    for(int i = n; i > 0; i-- )
    {
        if(ara[i].first >= n || i == n)
        {
            dp[i] = n - i;
            continue;
        }
        int MaxPoint = query(1,1,n,i + 1,ara[i].first).second;
        dp[i] = dp[MaxPoint] + MaxPoint - i + n - ara[i].first;
    }
    long long res = 0;
    for(int i = 1; i<=n; i++) res+=dp[i];
    cout << res << endl;
    return 0;
}
