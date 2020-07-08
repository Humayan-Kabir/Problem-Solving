/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-14 10:15:13
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
vector<pii> graph[mx];
LL dp[mx][2];
void rec(int u, int p) {
    LL optimal = 0;
    for(auto it : graph[u]) {
        int v = it.first, w = it.second;
        if(v != p) {
            rec(v, u);
            dp[u][0] += (dp[v][0] + 2 * w);
            optimal = max(optimal, dp[v][0] + 2 * w - w - dp[v][1]);
        }
    }
    dp[u][1] = dp[u][0] - optimal;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    rec(1, -1);
    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}