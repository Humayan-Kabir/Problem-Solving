#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int cnt[mx], cumu[mx], numTwo[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector < pair<int,int> > vt;
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        vt.push_back(make_pair(l, r));
        cnt[l] += 1;
        cnt[r + 1] -= 1;
    }
    int ans = n;
    for(int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + cnt[i];
        if(cnt[i] == 0) ans--;
    }
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 1) {
            cumu[i] = cumu[i - 1] + 1;
        }
        else cumu[i] = cumu[i - 1];
    }
    for(int i = 1; i <= n; i++ ) {
        if(cnt[i] == 2) {
            numTwo[i] = numTwo[i - 1] + 1;
        }
        else {
            numTwo[i] = numTwo[i - 1];
        }
    }
    sort(vt.begin(), vt.end());
    int res = 0;
    for(int i = 0; i < q; i++) {
        for(int j = i + 1; j < q; j++) {
            int l = vt[i].first , r = vt[i].second;
            int bad = cumu[r] - cumu[l - 1];
            l = max(r + 1, vt[j].first); r = vt[j].second;
            if(l <= r) {
                bad += (cumu[r] - cumu[l - 1]);
            }
            l = max(vt[i].first, vt[j].first);
            r = min(vt[i].second, vt[j].second);
            if(l <= r) {
                bad += (numTwo[r] - numTwo[l - 1]);
            }
            res = max(res, ans - bad);
        }
    }
    cout << res << endl;
    return 0;
}