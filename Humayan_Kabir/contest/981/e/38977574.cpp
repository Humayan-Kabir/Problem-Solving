/*
just copied from tourist
*/
#include<bits/stdc++.h>
#define mx 10007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector< vector<int> > tree(4 * mx);
    function< void(int,int,int,int,int,int) >update = [&] (int node,int l,int r,int x,int y, int val)
    {
        if(l > y || r < x) return;
        if(l >= x && r <= y)
        {
            tree[node].push_back(val);
            return;
        }
        int mid = (l + r) / 2;
        update(node + node, l, mid, x, y, val);
        update(node + node + 1, mid + 1, r, x, y, val);
    };
    for(int i = 1; i<=q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        update(1,1,n,l,r,x);
    }
    bitset<mx> ans;
    function< void(int,int,int,bitset<mx>) > solve = [&] (int node,int l,int r, bitset<mx> b)
    {
        for(int v : tree[node]) b |= (b << v);
        if(l == r)
        {
            ans |= b;
            return;
        }
        int mid = (l + r)/ 2;
        solve(node + node, l, mid, b);
        solve(node + node + 1, mid + 1, r, b);
    };
    bitset<mx> b;
    b.set(0);
    solve(1,1,n,b);
    vector<int> res;
    for(int i = 1; i<=n; i++)
        if(ans[i]) res.push_back(i);
    cout << res.size()<< endl;
    for(int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
