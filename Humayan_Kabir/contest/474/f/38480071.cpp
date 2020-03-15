#include<bits/stdc++.h>
#define mx 123456
using namespace std;
int tree[4 * mx], a[mx];
pair <int,int> ara[mx];
void build(int node,int l,int r)
{
    if(l == r)
    {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(node + node, l, mid);
    build(node + node + 1, mid + 1, r);
    tree[node] = __gcd(tree[node + node], tree[node + node + 1]);
}
int query(int node,int l,int r,int x,int y)
{
    if(r < x || l > y || l > r) return 0;
    if(l >= x && r <= y) return tree[node];
    int mid = (l + r) / 2;
    return __gcd(query(node + node, l, mid, x, y), query(node + node + 1, mid + 1, r, x, y));
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
        ara[i] = {a[i],i};
    }
    sort(ara + 1, ara + n + 1);
    build(1,1,n);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int Minimum = query(1,1,n,l,r);
        int from = upper_bound(ara + 1, ara + n + 1,make_pair(Minimum,l - 1)) - (ara + 1);
        int to = upper_bound(ara + 1, ara + n + 1,make_pair(Minimum,r)) - (ara + 1);
        cout << r - l + 1 + from - to << endl;
    }
    return 0;
}
