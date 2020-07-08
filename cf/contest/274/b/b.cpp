/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-20 12:03:07
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
LL arr[mx], ans = 0;
void dfs(int u, int p) {
    LL x = INT_MIN, y = INT_MAX, flag = 1;
    for(int v : graph[u]) {
        if(v == p) continue;
        x = max(x, arr[v]);
        y = min(y, arr[v]); 
        flag = 0;
    }
    if(flag) return;
    LL pre = arr[u];
    ans += abs(pre - x) + abs(pre - y);
    arr[u] += abs(pre - y);
    arr[u] -= abs(pre - x);
    ans += abs(pre - arr[u]);
    for(int v : graph[u])  {
        if(v == p) continue;
        arr[v] = arr[u];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}