#include<bits/stdc++.h>
using namespace std;
const int N = 1000007;
int vis[N], component[N], id[N], dp[N], Timer = 0, cmpId = 0;
vector<int> adj[N];
vector<int> revAdj[N];
vector<pair<int,int>> edges;
void dfs(int u) {
    vis[u] = Timer;
    component[u] = cmpId;
    id[cmpId] = u; 
    for(int v : revAdj[u]) {
        if (vis[v] != Timer) {
            dfs(v);
        }
    }
}
int dfs2(int u) {
    if (vis[u] == Timer) return dp[u];
    vis[u] = Timer;
    int total = 1;
    for(int v : adj[u]) {
        if (vis[v] != Timer) {
            total += dfs2(v);
        }
    }
    return dp[u] = total;
}
int main() {
    int t; scanf("%d", &t);
    for(int test = 1; test <= t; test++) {
        ++Timer;
        cmpId = 0;
        int n, m; scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++) {
            int u, v; scanf("%d %d", &u, &v);
            edges.push_back({u, v});
            revAdj[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            if (vis[i] != Timer) {
                cmpId++;
                dfs(i);
            }
        }
        for(int i = 0; i < edges.size(); i++) {
            int u = component[edges[i].first];
            int v = component[edges[i].second];
            if (u != v) adj[u].push_back(v);
        }
        Timer++;
        int found = 0;
        for(int i = 1; i <= cmpId; i++) {
            if(dfs2(i) == cmpId) {
                found = 1;
                printf("Case #%d: The desired island is %d\n", test, id[i]);
                break;
            }
        }
        if (!found) {
            printf("Case #%d: Doomed!\n", test);
        }
        for(int i = 1; i <= n; i++) {
            dp[i] = 0;
            adj[i].clear();
            revAdj[i].clear();
        }
        edges.clear();
    }
    return 0;
}