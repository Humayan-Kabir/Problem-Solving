/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-26 00:31:59
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<pair<int,int>> edges;
set<int> graph[mx];
void dfs(int u, int depth, int limit) {
    int k = limit - (depth > 0);
    while(!graph[depth + 1].empty() && k--) {
        int v = *graph[depth + 1].begin();
        edges.push_back({u, v});
        graph[depth + 1].erase(graph[depth + 1].begin());
        dfs(v, depth + 1, limit);
    }
} 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        graph[x].insert(i);
    }
    if(graph[0].size()) {
        dfs(*graph[0].begin(), 0, k);
    }
    if(edges.size() == n - 1) {
        cout << n - 1 << endl;
        for(auto it : edges) {
            cout << it.first << " " << it.second << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}