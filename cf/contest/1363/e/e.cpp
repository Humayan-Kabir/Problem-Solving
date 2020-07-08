/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-31 21:54:26
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int a[mx], b[mx], c[mx], x[mx], y[mx], in[mx], out[mx], tree[4 * mx], Timer = 0;
set<int> myset1, myset2;
vector<int> graph[mx];
void dfs(int u, int p) {
    in[u] = ++Timer;
    if(b[u] != c[u]) {
        if(b[u] == 0) {
            myset1.insert(in[u]);
            x[u] = 1;
        }
        if(b[u] == 1) {
            y[u] = 1;
            myset2.insert(in[u]);
        }
    }
    for(int v : graph[u]) {
        if(v != p) {
            dfs(v, u);
            x[u] += x[v];
            y[u] += y[v];
        }
    }
    out[u] = Timer;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<pair<int,int>> vt;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        vt.push_back({a[i], i});
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    sort(vt.begin(), vt.end());
    LL ans = 0, valid = 1;
    for(int i = 0; i < n; i++) {
        LL cost = vt[i].first, u = vt[i].second;
        auto it1 = myset1.upper_bound(in[u] - 1);
        auto it2 = myset2.upper_bound(in[u] - 1);
        while(it1 != myset1.end() && it2 != myset2.end() && (*it1 >= in[u] && *it1 <= out[u]) && (*it2 >= in[u] && *it2 <= out[u])) {
            ans += 1LL * 2 * cost;
            auto it3 = it1;
            auto it4 = it2;
            it1++;
            it2++;
            myset1.erase(it3);
            myset2.erase(it4);
        }
    }
    if(myset1.empty() && myset2.empty()) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}