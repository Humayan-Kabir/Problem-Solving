#include<bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second
#define mx 1000007
#define mod 1000000007
using namespace std;
typedef long long int LL;
map<int,int> maping;
long long vt[mx], tree[4 * mx], unq = 0;
void update(int node, int b, int e, int x, int y, long long val) {
    if(e < x || b > y) {
        return;
    }
    if(b >= x && e <= y) {
        tree[node] = (val) % mod;
        return;
    }
    int mid = (b + e) / 2, lson = 2 * node, rson = lson + 1;
    update(lson, b, mid, x, y, val); update(rson, mid + 1, e, x, y, val);
    tree[node] = (tree[lson] + tree[rson]) % mod;
}
int query(int node, int b, int e, int x, int y) {
    if(e < x || b > y) {
        return 0;
    }
    if(b >= x && e <= y) {
        return tree[node];
    }
    int mid = (b + e) / 2, lson = 2 * node, rson = lson + 1;
    return (query(lson, b, mid, x, y) + query(rson, mid + 1, e, x, y)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> vt[i];
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        long long int ret = query(1, 1, 1000000, 1, vt[i]);
        long long int cur = (ret * vt[i]) % mod + vt[i];
        update(1, 1, 1000000, vt[i], vt[i], cur);
    }
    for(int i = 1; i <= 1000000; i++) {
        ans = (ans + query(1, 1, n, i, i)) % mod;
    }
    cout << ans << endl;
    return 0;
}
