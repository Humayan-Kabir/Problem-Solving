/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-04-15 20:35:01
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
multiset<pair<LL,pair<LL,LL>>> myset;
void dfs(int u, int p, int depth) {
    int flag = 0;
    for(int v : graph[u]) {
        if(v == p) continue;
        dfs(v, u, depth + 1);
        flag = 1;
    }
    if(flag == 0) {
        myset.insert({(depth - 1) * -1LL,{0, depth}});
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1, 1);
    LL ans = 0;
    while(k > 0) {
        auto it = myset.begin();
        LL cnt = it->second.first + 1, depth = it->second.second;
        LL update = 2LL * -1 * cnt - 1 + depth; 
        ans += it->first * -1LL;
        myset.erase(myset.begin());
        myset.insert({update * -1LL, {cnt, depth}});
        k--;
    }
    cout << ans << endl;
    return 0;
}   