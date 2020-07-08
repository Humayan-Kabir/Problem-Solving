/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-14 13:19:35
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
vector<pii> graph[mx];
int ans[mx], vis[mx], color = 1;
void dfs(int u) {
    vis[u] = 1;
    for(auto it : graph[u]) {
        int v = it.first, id = it.second;
        if(vis[v] == 1) {
            ans[id] = 2; 
            color = 2;
        } else if(vis[v] == 2) {
            ans[id] = 1;
        } else {
            ans[id] = 1;
            dfs(v);
        }
    }
    vis[u] = 2;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v, i);
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] != 2) {
            dfs(i);
        }
    }
    cout << color << endl;
    for(int i = 1; i <= m; i++) {
        cout << ans[i] <<" ";
        if(i == m) cout << endl;
    }
    return 0;
}