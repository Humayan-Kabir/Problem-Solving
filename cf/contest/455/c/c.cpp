/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-24 05:31:41
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int parent[mx], diameter[mx];
vector<int> graph[mx];
int Find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}
void merge(int uu, int vv) {
    int u = Find(uu), v = Find(vv);
    if(u != v) {
        parent[u] = v;
        diameter[v] = max(max(diameter[u], diameter[v]), 1 + ((diameter[u] + 1) / 2) + ((diameter[v] + 1) / 2));
    }
}
int dfs(int u, int p, int leader) {
    parent[u] = leader;
    int child1 = 0, child2 = 0;
    for(int v : graph[u]) {
        if(v != p) {
            int d = dfs(v, u, leader);
            if(d + 1 > child1) {
                child2 = child1;
                child1 = d + 1;
            }
            else if(d + 1 > child2) {
                child2 = d + 1;
            }
        }
    }
    diameter[leader] = max(diameter[leader], child1 + child2);
    return child1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    for(int i = 1; i <= n; i++) {
        if(parent[i] == 0) {
            dfs(i, i, i);
        }
    }
    while(q--) {
        int t, u, v;
        cin >> t;
        if(t == 1) {
            int u;
            cin >> u;
            cout << diameter[Find(u)] << endl;
        } else {
            cin >> u >> v;
            merge(u, v);
        }
    }
    return 0;
}
