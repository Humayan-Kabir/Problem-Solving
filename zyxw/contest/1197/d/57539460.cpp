#include<bits/stdc++.h>
#define mx 300007
#define mod 998244353
using namespace std;
typedef long long int LL;
LL ara[mx], temp[mx],dp[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    LL m, k;
    cin >> n >> m  >> k;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        temp[i] = ara[i];
        ara[i] += ara[i - 1];
    }
    for(int i = m; i <= n; i++) {
        LL lastsum = ara[i] - ara[i - m] - k;
        dp[i] = max(dp[i], lastsum + dp[i - m]);
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        LL curSum = 0;
        for(int j = 0; j < m && (i - j) > 0; j++) {
            curSum += temp[i - j];
            LL curAns =  curSum - k + dp[i - j - 1];
            ans = max(ans, curAns);
        }
    }
    cout << ans << endl;
    return 0;
}