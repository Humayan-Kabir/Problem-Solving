/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-06-20 22:04:43
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int n, k, arr[mx], dp[mx][2], vis[mx][2], Timer = 0;
int rec(int pos, int type, int limit, int odd) {
    if(pos > n) return 0;
    int &v = vis[pos][type];
    int &ret = dp[pos][type];
    if(v == Timer) return ret;
    v = Timer;
    int now = 0;
    if(type == odd) {
        if(arr[pos] <= limit) {
            now = max(now, 1 + rec(pos + 1, type ^ 1, limit, odd));
            now = max(now, rec(pos + 1, type, limit, odd));
        }
        now = max(now, rec(pos + 1, type, limit, odd)); 
    } else {
        now = max(now, 1 + rec(pos + 1, type ^ 1, limit, odd));
        now = max(now, rec(pos + 1, type, limit, odd));
    }
    return ret = now;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = INT_MAX, low = 0, high = 1000000000;
    while(low <= high) {
        int mid = (low + high) / 2;
        Timer++;
        int x = rec(1, 1, mid, 1);
        Timer++;
        int y = rec(1, 1, mid, 0);
        if(x >= k || y >= k) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}