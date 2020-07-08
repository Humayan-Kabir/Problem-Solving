/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-23 02:54:58
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int in[mx], out[mx], depth[mx], Timer = 0; 
vector<int> graph[mx];
void dfs(int u, int p) {
    in[u] = ++Timer;
    for(int v : graph[u]) {
        if(v != p) {
            depth[v] = (depth[u] + 1) % 2;
            dfs(v, u);
        }
    }
    out[u] = Timer;
}
LL tree[2][mx];
void update(int idx, int index, int val) {
    while(idx < mx) {
        tree[index][idx] += val;
        idx += (idx & -idx);
    }
}
LL query(int idx, int index) {
    LL sum = 0;
    while(idx > 0) {
        sum += tree[index][idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        update(in[i], depth[i], arr[i]);
        update(in[i] + 1, depth[i], -arr[i]);
    }
    while(q--) {
        int t, x, val;
        cin >> t;
        if(t == 1) {
            cin >> x >> val;
            update(in[x], depth[x], val);
            update(out[x] + 1, depth[x], -val);
            update(in[x], depth[x] ^ 1, -val);
            update(out[x] + 1, depth[x] ^ 1, val);
        } else {
            cin >> x;
            cout << query(in[x], depth[x]) << endl;
        }
    }
    return 0;
}