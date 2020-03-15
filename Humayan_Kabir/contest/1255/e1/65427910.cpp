#include<bits/stdc++.h>
#define mx 1000007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
int n, ar[mx];
vector<LL> vt;
LL sum[mx], cntsum[mx];
inline LL fun(int l, int r) {
    LL res = 1e18 + 1e18, lcnt = 0, tcnt = 0, cnt = cntsum[r] - cntsum[l - 1];
    for(int i = l; i <= r; i++) {
        LL leftsum = sum[i - 1] - sum[l - 1];
        LL rightsum = sum[r] - sum[i];
        LL leftcnt = cntsum[i - 1] - cntsum[l - 1];
        LL rightcnt = cntsum[r] - cntsum[i];
        LL ans = leftcnt * i - leftsum + rightsum - rightcnt * i;
        // cout << ans << endl;
        res = min(res, ans);
    }
    return res;
}
inline LL check(LL v) {
    LL l = 1, r, ans = 0, paice = 0, cnt = 0, total = 0;
    for(int i = 1; i <= n; i++) {
        if(ar[i] == 0) continue;
        if(ar[i] > 0 && paice == 0) {
            paice = 1;
            l = i;
        }
        if(cntsum[i] % v == 0) {
            // cout << l << " .. " << i << endl;
            ans += fun(l, i);
            paice = 0;        
        }
    }
    return ans;
}
inline void init(LL v) {
    for(int i = 1; i <= n; i++) {
        LL id = ar[i] % v; 
        sum[i] = sum[i - 1] + 1LL* id * i;
        cntsum[i] = cntsum[i - 1] + 1LL * id;
    }
}
int main() {
    LL total = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ar[i]);
        total += ar[i];
    }
    if(total == 0) {
        printf("-1\n");
        return 0;
    }
    LL root = sqrt(total);
    for(LL i = 2; i <= root; i++) {
        if(total % i == 0) {
            vt.push_back(i);
            LL ret = total / i;
            if(ret != i) {
                vt.push_back(ret);
            }
        }
    }
    LL ans = 1e18 + 1e18, tmp = ans;
    if(total > 1) {
        vt.push_back(total);
    }
    for(int v : vt) {
        // cout << v << endl;
        init(v);
        ans = min(check(v), ans);
    }
    if(ans >= 1e18) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;  
}