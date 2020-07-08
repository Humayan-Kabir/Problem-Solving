/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-11 22:30:10
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
#define INFINITY 1000000000
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
vector<int> dist[2];
vector<int> favourite;
void dfs(int from, int idx) {
    dist[idx][from] = 0;
    queue<int> q; q.push(from);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : graph[u]) {
            if(dist[idx][v] > dist[idx][u] + 1) {
                dist[idx][v] = dist[idx][u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        int idx; cin >> idx;
        favourite.emplace_back(idx);
    }
    for(int i = 1; i <= m; i++) {
        int u, v; 
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    dist[0] = vector<int> (n + 1, INFINITY);
    dist[1] = vector<int> (n + 1, INFINITY);
    dfs(1, 0); dfs(n, 1);
    vector<pair<int,int>> vt;
    for(int v : favourite) {
        vt.push_back({dist[0][v] - dist[1][v], v});
    }
    sort(vt.begin(), vt.end());
    int ans = 0, pre = dist[0][vt[0].second];
    for(int i = 1; i < k; i++) {
        ans = max(ans, pre + dist[1][vt[i].second] + 1);
        pre = max(pre, dist[0][vt[i].second]);
    }
    cout << min(ans, dist[0][n]) << endl;
    return 0;
}