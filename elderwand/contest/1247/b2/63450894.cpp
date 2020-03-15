#include<bits/stdc++.h>
#define mod 1000000007
#define mx 3000007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
int ara[mx], tree[mx], pre[mx], vis[mx], Timer = 0;
void update(int idx, int n, int val) {
    while (idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
    return;
}
int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, k, d;
        cin >> n >> k >> d;
        for(int i = 1; i <= n; i++) {
            tree[i] = 0;
            cin >> ara[i];
        }
        int ans = k;
        Timer++;
        for(int i = 1; i <= n; i++) {
            if(vis[ara[i]] != Timer) {
                vis[ara[i]] = Timer;
                update(i, n, 1);
                pre[ara[i]] = i;
            }
            else {
                update(pre[ara[i]], n, -1);
                update(i, n, 1);
                pre[ara[i]] = i;
            }
            if(i >= d) {
                int ret = query(i) - query(i - d);
                ans = min(ans, ret);
            }
        }
        cout << ans << endl;
    }
    return 0;
}