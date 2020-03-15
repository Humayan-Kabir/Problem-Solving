#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
LL n, k, ara[mx], pre[mx], post[mx], sum[mx];
LL find(LL low, LL high, LL val) {
    if(val <= 0) return 0;
    LL ans = low;
    while(low <= high) {
        LL mid = (low + high) / 2;
        if(ara[mid] <= val) {
            ans = max(mid, ans);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}
int check(LL mid) {
    LL ans = 1e18;
    for(int i = 1; i <= n; i++) {
        LL idx = find(1LL*i, n, ara[i] + mid);
        LL idx2 = find(1LL, 1LL*i, ara[i] - mid);
        LL ret = 0, cnt = n - idx;
        ret += (sum[n] - sum[idx]) - (ara[i] + mid) * cnt;
        ret += (1LL * i * ara[i] - sum[i]);
        ans = min(ans, ret);
    }
    for(int i = n; i >= 1; i--) {
        LL idx = find(1LL, 1LL*i, ara[i] - mid);
        //cout << " n "<< i <<" "<< idx << endl;
        LL ret = 0, cnt = idx, baki = n - i + 1;
        ret += ((cnt * (ara[i] - mid)) - sum[idx]);
        //cout << ret << endl;
        ret += (sum[n] - sum[i - 1] - 1LL * ara[i] * baki) ;
        //cout << ret << endl;
        ans = min(ans, ret);
    }
    if(ans <= k) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    sort(ara + 1, ara + n + 1);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + ara[i];
    }
    LL ans = ara[n] - ara[1], low = 0, high = ans;
    while(low <= high) {
        LL mid = (low + high) / 2;
        if(check(mid)) {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    //check(1);
   // cout << find(1LL, 3LL, 4LL) << endl;
    cout << ans << endl;
    return 0;
}