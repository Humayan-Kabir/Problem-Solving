#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int n, m, grid[20][20], dp[1 << 20];
int rec(int mask, int pos) {
    if(pos == m) {
        return 0;
    }
    int &ret = dp[mask], now = 1e9;
    if(ret != -1) return ret;
    for(int i = 0; i < m; i++) {
        if(!(mask & 1 << i)) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                if(i == j) continue;
                if(mask & (1 << j)) {
                    sum += pos * grid[i][j];
                }
                else {
                    sum -= pos * grid[i][j];
                }
            }
            now = min(now, sum + rec(mask | 1 << i, pos + 1));
        }
    }
    return ret = now; 
}
int main() {
    ios_base::sync_with_stdio(false);
    string str;
    cin >> n >> m;
    cin >> str;
    for(int i = 0; i < n - 1; i++) {
        int u = str[i] - 'a';
        int v = str[i + 1] - 'a';
        grid[u][v]++;
        grid[v][u]++;
    }
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0) << endl;
    return 0;
}