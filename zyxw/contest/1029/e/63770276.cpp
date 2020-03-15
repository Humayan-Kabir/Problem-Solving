#include<bits/stdc++.h>
#define mx 200007
#define pii pair<int,int> 
using namespace std;
typedef long long int LL;
namespace treeWithSmallDistance {
    vector<int> g[mx];
    set<pii> st;
    int depth[mx], parent[mx];
    void dfs(int u, int p, int d) {
        parent[u] = p; depth[u] = d;
        for(int v : g[u]) {
            if(v != p) 
                dfs(v, u, d + 1);
        }
        if(depth[u] > 2) st.insert({-depth[u], u}); 
    }
    void solve() {
        int n;
        scanf("%d", &n);
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0, 0);
        int ans = 0;
        while (!st.empty()) {
            int u = st.begin()->second;
            u = parent[u];
            auto it = st.find({-depth[u], u});
            if(it != st.end()) st.erase(it);
            for(int v : g[u]) {
                auto it = st.find({-depth[v], v});
                if(it != st.end()) st.erase(it);
            }
            ans++;
        }
        printf("%d\n", ans);
    }
}
int main() {
    treeWithSmallDistance::solve();
    return 0;
}