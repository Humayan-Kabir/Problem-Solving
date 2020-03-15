#include<bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
namespace validSets {
    const int modulo = 1e9 + 7; 
    int a[2001];
    vector<int> graph[2001];
    int dfs(int u, int p, int d, int from, int vis[]) {
        int ans = 1;
        for(int v : graph[u]) {
            if(v == p || a[v] < a[from] || a[v] - a[from] > d) continue;
            if(a[v] == a[from] && vis[v]) continue;
            ans = (1LL * ans * (dfs(v, u, d, from, vis) + 1)) % modulo; 
        }
        return ans;
    }
    void solve() {
        int n, d;
        scanf("%d %d", &d, &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans = 0;
        int vis[2001] = {0};
        for(int i = 1; i <= n; i++) {
             ans = (ans + dfs(i, i, d, i, vis));
             ans %= modulo;
             vis[i] = 1;
        }
        printf("%d\n", ans);
    }
}
int32_t main() {
    validSets::solve();
    return 0;
}