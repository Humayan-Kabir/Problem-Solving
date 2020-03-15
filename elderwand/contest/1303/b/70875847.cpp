#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        LL n, g, b;
        cin >> n >> g >> b;
        LL low = 1, high = 1e18, ans = 1e18 + 1, need = (n + 1) / 2LL, t = g + b;
        while(low <= high) {
            LL mid = (low + high) / 2LL, group = mid / t, day = group * g + min(g, mid % t);
            if(day >= need && mid >= n) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}   