/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-20 23:11:52
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
map<pair<int,int>, int> edges;
int parent[20][mx], depth[mx], tree[mx], res[mx];
void dfs(int u, int p) {
    parent[0][u] = p;
    for(int v : graph[u]) {
        if(v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}
int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    for(int j = 19; j >= 0; j--) {
        if(depth[v] - (1 << j) >= depth[u]) {
            v = parent[j][v];
        }
    }
    if(u == v) return u;
    for(int j = 19; j >= 0; j--) {
        if( parent[j][u] != parent[j][v]) {
            u = parent[j][u];
            v = parent[j][v];
        }
    }
    return parent[0][u];
}
void update(int u, int v) {
    tree[u] -= 1;
    tree[v] += 1;
}
void rec(int u, int p) {
    for(int v : graph[u]) {
        if(v != p) {
            rec(v, u);
            tree[u] += tree[v];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[{u, v}] = i;
        edges[{v, u}] = i; 
    }
    dfs(1, 0);
    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        int LCA = lca(u, v);
        update(LCA, u);
        update(LCA, v);
    }    
    rec(1, 0);
    for(int i = 2; i <= n; i++) {
        res[edges[{i, parent[0][i]}]] = tree[i];
    }
    for(int i = 1; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}