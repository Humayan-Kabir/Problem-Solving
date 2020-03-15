#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int a[mx], p[mx], vis[102];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= m; i++) {
            cin >> p[i];
            vis[p[i]] = 1;
        }
        // cout << vis[1] << " " << vis[2] << " " << vis[3] << endl;
        sort(p + 1, p + m + 1);
        for(int i = 1; i <= m; i++) {
            int curpos = p[i];
            while(vis[curpos]) {
                curpos++;
                // cout << "INSIDE " << curpos << endl;
            }
            // cout << p[i] << " ... " << curpos << endl;
            sort(a + p[i], a + curpos + 1);
        }
        int flag = 1;
        for(int i = 2; i <= n; i++) {
            if(a[i] >= a[i - 1]) continue;
            flag = 0;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}