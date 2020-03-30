/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: Humayan Kabir
 * Time: 2020-03-26 20:39:02
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int in[mx], out[mx], parent[mx], level[mx], Timer = 0;
void dfs(int u, int p, int depth) {   
    level[u] = depth;
    in[u] = ++Timer; 
    parent[u] = p; 
    for(int v : graph[u]) {
        if(v == p) continue;
        dfs(v, u, depth + 1);
    }
    out[u] = Timer;
}
bool isAncestor(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 1, 0);
    while(m--) {
        int k;
        cin >> k;
        int farthest = 1, arr[k + 1];
        for(int i = 1; i <= k; i++) {
            cin >> arr[i];
            if(level[arr[i]] >= level[farthest]) {
                farthest = arr[i];
            }
            arr[i] = parent[arr[i]];
        }
        int flag = 1;
        for(int i = 1; i <= k; i++) {
            flag = flag & isAncestor(arr[i], farthest);
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}