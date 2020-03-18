#include<bits/stdc++.h>
using namespace std;
namespace solver {
    const int mx = 5001;
    pair<int,int> arr[mx];
    vector<int> graph[mx];
    int dp[mx], vis[mx];
    int check(int i, int j) {
        if(arr[i].first > arr[j].first && arr[i].second > arr[j].second) return 1;
        if(arr[i].first > arr[j].second && arr[i].second > arr[j].first) return 1;
        if(arr[i].second > arr[j].first && arr[i].first > arr[j].second) return 1;
        if(arr[i].second > arr[j].second && arr[i].first > arr[j].first) return 1;
        return 0;
    }
    int rec(int u) {
        if(vis[u]) return dp[u];
        dp[u] = vis[u] = 1;
        for(int v : graph[u]) {
            dp[u] = max(dp[u], 1 + rec(v));
        }
        return dp[u];
    }
    void solve() {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(check(i, j)) {
                    graph[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) rec(i);
        for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        cout << ans << endl;
    }
}
int main() {
    solver::solve();
    return 0;
}