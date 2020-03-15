#include<bits/stdc++.h>
#define mx 300007
#define mod 1000000007
#define int long long
using namespace std;
typedef long long LL;
namespace levkoAndArray {
    const int modulo = 1e9 + 7;
    void solve() {
        int n, k, a[2001];
        scanf("%lld %lld", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", a + i);
        }
        int low = 0, high = 2e9, ans = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            int dp[n + 1] = {0};
            for(int i = 1; i <= n; i++) {
                for(int j = i; j >= 1; j--) {
                    if(abs(a[i] - a[j]) <= (i - j) * mid) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            int flag = 0;
            for(int i = 1; i <= n; i++) {
                flag |= dp[i] >= n - k;
            }
            if(flag) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        printf("%lld\n", ans);
    }
}
int32_t main() {
    levkoAndArray::solve();
    return 0;
}