#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
LL a[mx], b[mx], dp[mx][10];
int n;
LL rec(int pos, int pre) {
    if(pos > n) {
        return 0;
    }
    LL &ret = dp[pos][pre];
    if(ret != -1) return ret;
    LL now = 1e17;
    if(pos == 1) {
        for(int j = 0; j < 9; j++) {
            now = min(now, j * b[pos] + rec(pos + 1, j));
        }
    }
    else {
        for(int j = 0; j < 9; j++) {
            if((a[pos - 1] + pre) != (a[pos] + j)) {
                now = min(now, j * b[pos] + rec(pos + 1, j));
            }
        }
    }
    return ret = now;
}
int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(false);
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lld %lld", &a[i], &b[i]);
            for(int j = 0; j < 9; j++) {
                dp[i][j] = -1;
            }
        }
        LL ans = rec(1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
