/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-17 13:35:38
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int color[mx], dpDown[mx][2], dpUp[mx];
void rec(int u,int p) {
    dpDown[u][0] = dpDown[u][1] = dpUp[u] = INT_MIN;
    if(color[u]) dpDown[u][0] = 0;
    for(int v : graph[u]) {
        if(v != p) {
            rec(v, u);
            if(dpDown[v][0] + 1 > dpDown[u][0]) {
                dpDown[u][1] = dpDown[u][0];
                dpDown[u][0] = dpDown[v][0] + 1;
            } else if(dpDown[v][0] + 1 > dpDown[u][1]) {
                dpDown[u][1] = dpDown[v][0] + 1;
            }
        }
    }
}
void dfs(int u, int p) {
    for(int v : graph[u]) {
        if(v != p) {
            dpUp[v] = max(dpUp[u] + 1, dpUp[v]);
            if(dpDown[v][0] == dpDown[u][0] - 1) {
                dpUp[v] = max(dpDown[u][1] + 1, dpUp[v]);
            } else {
                dpUp[v] = max(dpDown[u][0] + 1, dpUp[v]);                
            }
            dfs(v, u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i++) {
        int node; cin >> node;
        color[node] = 1;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    rec(1, -1);
    dfs(1, -1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dpDown[i][0] <= d && dpUp[i] <= d) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}