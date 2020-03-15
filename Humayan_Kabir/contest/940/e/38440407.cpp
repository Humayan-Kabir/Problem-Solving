#include<bits/stdc++.h>
#define mx 100007
using namespace std;
long long tree[4 * mx][2], dp[mx];
void update(int node,int l,int r, int x,int id,long long val)
{
    if(l == r)
    {
        tree[node][id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) update(2 * node, l, mid, x, id, val);
    else update(2 * node + 1, mid + 1, r, x, id, val);
    if(id == 0)
        tree[node][id] = min(tree[2 * node][id], tree[2 * node + 1][id]);
    else
        tree[node][id] = max(tree[2 * node][id], tree[2 * node + 1][id]);
}
long long query(int node,int l,int r, int x,int y,int id)
{
    if(r < x || l > y || l > r) return 0 + (id == 0) * 1000000000000000000 * 1LL;
    if(l >= x && r <= y)
    {
        return tree[node][id];
    }
    int mid = (l + r) / 2;
    if(id == 0)
        return min(query(2 * node, l, mid, x, y, id), query(2 * node + 1, mid + 1, r, x, y, id));
    else
        return max(query(2 * node, l, mid, x, y, id), query(2 * node + 1, mid + 1, r, x, y, id));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    long long res = 0, maxDp = 0;
    for(int i = 1; i<=n; i++)
    {
        long long num;
        cin >> num;
        res += num;
        update(1,1,n,i,0,num);
    }
    if(c == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i<=n; i++)
    {
        if(i < c)
        {
            dp[i] = 0;
            update(1,1,n,i,1,0);
            continue;
        }
        else
        {
            dp[i] = (maxDp, query(1,1,n,i - c + 1, i,0) + query(1,1,n,1,i - c,1));
            maxDp = max(maxDp,dp[i]);
            update(1,1,n,i,1,dp[i]);
        }
       /// cout << i << " .. "<< dp[i] << endl;
    }
    cout << res - maxDp << endl;
    return 0;
}
