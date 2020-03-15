#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
int mxdist = -1, node = 0;
void findfarthest(int u, int dist, int par) {
    if(dist > mxdist) {
        mxdist = dist; node = u;
    }
    for(int v : graph[u]) {
        if(v != par) {
            findfarthest(v, dist + 1, u);
        }
    }
}
int parent[mx], vis[mx], dist[mx];
void dfs(int u, int par) {
    parent[u] = par;
    for(int v : graph[u]) {
        if(v != par) {
            dfs(v, u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int a = 0, b = 0, c = 0;
    mxdist = -1;
    findfarthest(1, 0, -1);
    a = node;
    mxdist = -1;
    findfarthest(a, 0, -1);
    b = node;
    dfs(a, -1);
    vis[b] = 1; vis[a] = 1;
    int temp = b;
    while(parent[temp] != a) {
        temp = parent[temp];
        vis[temp] = 1;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) q.push(i);
        if(i != a && i != b) c = i;
    }
    int now = 0, total = mxdist;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : graph[u]) {
            if(vis[v] == 0) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                if(dist[v] > now) {
                    now = dist[v];
                    c = v;
                }
                q.push(v);
            }
        }
        
    }
    cout << mxdist + now << endl;
    cout << a << " " << b << " " << c << endl;
    return 0;
}