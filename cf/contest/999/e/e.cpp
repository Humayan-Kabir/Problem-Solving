/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-02 23:43:08
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx], rgraph[mx];
set<int> compressedGraph[mx];
vector<int> topSort;
int vis[mx], compNo[mx], Timer = 0;
void dfs(int u) {
    vis[u] = Timer;
    for(int v : graph[u]) {
        if(vis[v] != Timer) {
            dfs(v);
        }
    }
    topSort.push_back(u);
}
void dfs2(int u, int comp) {
    vis[u] = Timer;
    compNo[u] = comp;
    for(int v : rgraph[u]) {
        if(vis[v] != Timer) {
            dfs2(v, comp);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    Timer++; 
    for(int i = 1; i <= n; i++) {
        if(vis[i] != Timer) {
            dfs(i);
        }
    }
    int counter = 0;
    reverse(topSort.begin(), topSort.end()); Timer++;
    for(int v : topSort) {
        if(vis[v] != Timer) {
            dfs2(v, ++counter);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j : graph[i]) {
            if(compNo[i] != compNo[j]) {
                compressedGraph[compNo[j]].insert(compNo[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= counter; i++) {
        if(compNo[s] == i) continue;
        if(compressedGraph[i].size() == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}