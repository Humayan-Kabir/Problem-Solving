#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int ara[mx], tree[4 * mx], LisfromLeft[mx], LisfromRight[mx], ans[mx];
void update(int node,int l,int r, int x, int val)
{
    if(r < x || l > x || l > r) return;
    if(l >= x && r <= x)
    {
        tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * node, l, mid, x, val);
    update(2 * node + 1, mid + 1, r, x, val);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int node,int l,int r, int x, int y)
{
    if(r < x || l > y || l > r) return 0;
    if(l >= x && r <= y) return tree[node];
    int mid = (l + r) / 2;
    return max(query(2 * node, l, mid, x, y), query(2 * node + 1, mid + 1, r, x, y));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, LIS = 0;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> ara[i];
    for(int i = 1; i<=n; i++)
    {
        LisfromLeft[i] = query(1,1,mx-1,1,ara[i] - 1) + 1;
        update(1,1,mx-1,ara[i],LisfromLeft[i]);
        LIS = max(LIS,LisfromLeft[i]);
    }
    memset(tree,0,sizeof tree);
    for(int i = n; i>=1; i--)
    {
        LisfromRight[i] = query(1,1,mx-1,ara[i] + 1, mx - 1) + 1;
        update(1,1,mx-1,ara[i],LisfromRight[i]);
    }
    int prev = 0;
    for(int i = 1; i<=n; i++)
    {
        if(LisfromLeft[i] + LisfromRight[i] - 1 < LIS) ans[i] = 1;
        else if(prev >= ara[i]) ans[i] = 2;
        else prev = ara[i];
    }
    prev = INT_MAX;
    for(int i = n; i>=1; i--)
    {
        if(LisfromLeft[i] + LisfromRight[i] - 1 < LIS) ans[i] = 1;
        else if(prev <= ara[i]) ans[i] = 2;
        else prev = ara[i];
    }
    for(int i = 1; i<=n; i++)
    {
        if(ans[i] == 1 || ans[i] == 2) cout << ans[i];
        else cout << 3;
    }
    cout << endl;
    return 0;
}