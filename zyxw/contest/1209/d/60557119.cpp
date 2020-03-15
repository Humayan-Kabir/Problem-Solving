#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int parent[mx], vis[mx], counter;
pair<int,int> edge[mx];
int find(int u) {
  if(parent[u] == u) return u;
  return parent[u] = find(parent[u]);
}
vector<int> graph[mx];
void dfs(int u) {
  vis[u] = 1;
  counter++;
  for(int v : graph[u]) {
    if(vis[v]) continue;
    dfs(v);
  }
}
int main() {
  //ios_base::sync_with_stdio(false);
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d %d", &edge[i].first, &edge[i].second);
  }
  for(int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  for(int i = 1; i <= m; i++) {
    int u = edge[i].first, v = edge[i].second;
    int x = find(u), y = find(v);
    if(x == y) {
      continue;
    }
    else {
      graph[u].push_back(v);
      graph[v].push_back(u);
      parent[y] = x;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    counter = 0;
    if(vis[i] == 0) {
      dfs(i);
     // cout << counter << " .. " << i << endl;
      ans += max(0, counter - 1);
    }
  }
  cout << max(0, m - ans) << endl;
  return 0;
}

