/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-03-31 19:35:02
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
vector<int> graph[mx];
string str;
int vis[mx], Timer = 0, nodes = 0, arr[26];
void dfs(int u) {
    arr[str[u - 1] - 'a']++;
    vis[u] = Timer;
    for(int v : graph[u]) {
        if(vis[v] != Timer) {
            dfs(v);
        }
    }
    nodes++;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cin >> str;
        int ans = n;
        for(int i = k + 1; i <= n; i++) {
            graph[i].push_back(i - k);
            graph[i - k].push_back(i);
        }
        for(int i = 1, j = n; i < j; i++, j--) {
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
        Timer++;
        int now = 0;
        for(int i = 1; i <= n; i++) {
            nodes = 0; memset(arr, 0, sizeof arr);
            if(vis[i] != Timer) {
                dfs(i);
                int cur = 0;
                for(int j = 0; j < 26; j++) {
                    cur = max(cur, arr[j]);
                }
                now += (nodes - cur); 
                // cout << i << " " << nodes << " " << now << endl;               
            }
        }
        for(int i = 1; i <= n; i++) graph[i].clear();
        cout << min(ans, now) << endl;
    }
    return 0;
}