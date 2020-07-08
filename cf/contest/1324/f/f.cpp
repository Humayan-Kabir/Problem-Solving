/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-12 16:03:03
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int color[mx], dpDown[mx], dpUp[mx];
vector<int> graph[mx];
void dfs1(int u, int p) {
    dpDown[u] = color[u];
    for(int v : graph[u]) {
        if(v != p) {
            dfs1(v, u);
            if(dpDown[v] > 0) dpDown[u] += dpDown[v];
        }
    }
}
void dfs2(int u, int p) {
    dpUp[u] = dpUp[p] + dpDown[p];
    if(dpDown[u] > 0) dpUp[u] -= dpDown[u];
    if(dpUp[u] < 0) dpUp[u] = 0;    
    for(int v : graph[u]) {
        if(v != p) {
            dfs2(v, u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> color[i]; 
        if(color[i] == 0) color[i] = -1;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    dfs1(1, 0); dfs2(1, 0);
    for(int i = 1; i <= n; i++) {
        if(i > 1) cout << " ";
        cout << dpDown[i] + dpUp[i];
    }
    cout << endl;
    return 0;
}