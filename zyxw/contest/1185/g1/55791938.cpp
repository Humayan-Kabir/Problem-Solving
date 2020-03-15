#include<bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int n, t, ti[mx], gi[mx];
int dp[1 << 15][4][226], limit;
LL rec(int mask, int pre, int Time) {
   // cout << mask << " " << pre << " " << Time << endl;
    if(Time == t) return 1;
    if(mask == limit) {
        return Time == t;
    }
    int &ret = dp[mask][pre][Time];
    if(ret != -1) return ret;
    LL way = 0;
    for(int j = 0; j < n; j++) {
        if(mask & (1 << j)) continue;
        if(pre != gi[j] && Time + ti[j] <= t) {
            way = way + rec(mask | (1 << j), gi[j], Time + ti[j]);
            way = way % mod; 
        }
    }
    return ret = way;
}
int main() {
    //ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &t);
    limit = (1 << n) - 1;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &ti[i], &gi[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("%lld\n", rec(0, 0, 0));
    return 0;
}