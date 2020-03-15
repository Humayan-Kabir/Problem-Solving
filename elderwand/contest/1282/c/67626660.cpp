#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int a[mx], b[mx];
vector<pair<int,int>> vt;
inline int fun(LL cnt1, LL cnt2, LL u, LL v, LL x, LL y, LL out) {
    if(out == 0) return 0;
    LL res = 0, need = u * x + v * y;
    if(need <= out) {
        res = u + v;
        out -= need;
        cnt1 -= u; cnt2 -= v;
        LL possiblea = min((out / x), cnt1);
        out -= (possiblea * x);
        LL possibleb = min((out/y), cnt2);
        out -= (possibleb * y);
        res += (possibleb + possiblea);
        return res;
    } else {
        return 0;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, t, x, y;
        LL cnt1 = 0, cnt2 = 0;
        cin >> n >> t >> x >> y;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] == 0) cnt1++;
            else cnt2++;
        }
        vt.clear();
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            vt.push_back(make_pair(b[i], a[i]));
        }
        vt.push_back(make_pair(INT_MIN, INT_MIN));
        int ans = 0;
        LL u = 0, v = 0;
        sort(vt.begin(), vt.end());
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                if(vt[i].second == 0) u++;
                else v++;
                continue;
            } else {
                if(vt[i].first != vt[i - 1].first) {
                    ans = max(ans, fun(cnt1, cnt2, u, v, x, y, 1LL * vt[i].first - 1));
                }
            }
            if(vt[i].second == 0) u++;
            else v++;
        }
        ans = max(ans, fun(cnt1, cnt2, u, v, x, y, 1LL * t));
        ans = max(ans, fun(cnt1, cnt2, 0, 0, x, y, vt[1].first - 1));
        cout << ans << endl;
    }
    //resubmit
    return 0;
}