/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-03-31 00:28:38
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int n, m, q, ans[mx], parent[mx], height[500][500];
vector<pair<int,pair<int,int>>> edges;
set<int> myset[mx];
bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int id(int x, int y) {
    return x * m + y;
}
void genAllEdges() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(isValid(i - 1, j)) {
                edges.push_back({max(height[i][j], height[i - 1][j]),{id(i, j), id(i - 1, j)}});
            }
            if(isValid(i + 1, j)) {
                edges.push_back({max(height[i][j], height[i + 1][j]),{id(i, j), id(i + 1, j)}});
            }
            if(isValid(i, j - 1)) {
                edges.push_back({max(height[i][j], height[i][j - 1]),{id(i, j), id(i, j - 1)}});
            }
            if(isValid(i, j + 1)) {
                edges.push_back({max(height[i][j], height[i][j + 1]),{id(i, j), id(i, j + 1)}});
            }
        }
    }
}
void init() {
    for(int i = 0; i <= id(n - 1, m - 1); i++) {
        parent[i] = i;
    }
}
int Find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}
void Union(int u, int v, int cost) {
    u = Find(u), v = Find(v);
    if(u == v) {
        return;
    }
    if(myset[u].size() < myset[v].size()) {
        swap(u, v);
    }
    for(int x : myset[v]) {
        if(myset[u].find(x) != myset[u].end()) {
            ans[x] = cost;
            myset[u].erase(myset[u].find(x));
        } else {
            myset[u].insert(x);
        }
    }
    parent[v] = u;
    myset[v].clear();
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> height[i][j];
        }
    }
    init();
    genAllEdges();
    sort(edges.begin(), edges.end());
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int u = id(x1 - 1, y1 - 1), v = id(x2 - 1, y2 - 1);
        if(u == v) {
            ans[i] = height[x1 - 1][y1 - 1];
            continue;
        }
        myset[u].insert(i); myset[v].insert(i);
    }
    for(auto it : edges) {
        Union(it.second.first, it.second.second, it.first);
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}