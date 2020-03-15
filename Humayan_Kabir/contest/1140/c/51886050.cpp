#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
multiset <LL> myset;
LL ara[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector < pair <LL,LL> > vt;
    for(int i = 1; i <= n; i++) {
        LL ti, bi;
        cin >> ti >> bi;
        vt.push_back(make_pair(bi, ti));
    }
    sort(vt.rbegin(), vt.rend());
    LL total = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(i < k) {
            total += vt[i].second;
            myset.insert(vt[i].second);
            ans = max(ans, (total * vt[i].first));
        }
        else {
            LL temp = total - (*myset.begin()) + vt[i].second;
            ans = max(ans, (temp * vt[i].first));
            if((*myset.begin()) < vt[i].second) {
                LL v = (*myset.begin());
                myset.erase(myset.find(v));
                myset.insert(vt[i].second);
                total = total - v + vt[i].second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}