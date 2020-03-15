#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
namespace beautifulArray {
    int n, x;
    LL sum[mx], dp[mx], revdp[mx];
    void solve() {
        scanf("%d %d", &n, &x);
        LL pre = 1e16, ans = 0;
        for(int i = 1; i <= n; i++) {
            int num;
            scanf("%d", &num);
            sum[i] = sum[i - 1] + num;
            if(i != 1) {
                dp[i] = max(0LL, sum[i] - pre);
            }
            dp[i] = max(dp[i], sum[i]);
            pre = min(pre, sum[i]);
            ans = max(ans, dp[i]);
        }
        pre = 1e16;
        for(int i = n; i >= 1; i--) {
             if(i != n) {
                revdp[i] = max(0LL, sum[n] - sum[i - 1] - pre);
            }
            revdp[i] = max(revdp[i], sum[n] - sum[i - 1]);
            pre = min(pre, sum[n] - sum[i - 1]);
            ans = max(ans, revdp[i]);
        }
        pre = 1e16;
        for(int i = 1; i <= n; i++) {
            if(i != 1) {
                ans = max(ans, sum[i] * x - pre + revdp[i + 1]);
            }
            ans = max(ans, sum[i] * x + revdp[i + 1]);
            pre = min(pre, x * sum[i] - dp[i]);
        }
        printf("%lld\n", ans);
    }
} // namespace beautifulArray
 
int main() {
    ios_base::sync_with_stdio(false);
    beautifulArray::solve();
    return 0;
}