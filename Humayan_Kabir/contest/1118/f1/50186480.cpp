#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
vector <int> graph[mx];
int n, black = 0, red = 0, uncolored = 0, ans = 0;
int cntEachNode[mx][3], color[mx];
void dfs(int u, int par) {
    cntEachNode[u][color[u]]++;
    for(int v : graph[u]) {
        if(v == par) continue;
        dfs(v, u);
        for(int j = 0; j < 3; j++) {
            cntEachNode[u][j] += cntEachNode[v][j];
        }
        int x = black - cntEachNode[v][1];
        int y = red - cntEachNode[v][2];
        if((x > 0 && y > 0) || (cntEachNode[v][1] > 0 && cntEachNode[v][2] > 0)) continue;
        ans++;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
        if(color[i] == 1) black++; 
        else if(color[i] == 2) red++;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}