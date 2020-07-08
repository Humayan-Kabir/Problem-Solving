/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: elderwand
 * Time: 2020-05-10 00:00:54
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
long long int ans = 0;
vector<int> dfs(int u, int p, int k) {
    vector<int> counter(k + 1, 0);
    counter[0] = 1;
    for(int v : graph[u]) {
        if(v != p) {
            vector<int> ret = dfs(v, u, k);
            for(int i = 0; i < k; i++) {
                ans += 1LL * counter[k - i - 1] * ret[i];
            }
            for(int i = 0; i < k; i++) {
                counter[i + 1] += ret[i];
            }
        }
    }
    return counter;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin  >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    } 
    dfs(1, -1, k);
    cout << ans << endl;
    return 0;
}