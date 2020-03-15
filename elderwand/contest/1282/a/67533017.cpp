#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, rr;
        cin >> a >> b >> c >> rr;
        if(a > b) swap(a, b);
        int l = c - rr, r = c + rr, ans = b - a;
        if(l > b) {
            cout << ans << endl;
        } else if(r < a) {
            cout << ans << endl;
        } else {
            int x = max(l, a), y = min(r, b);
            cout << ans - (y - x) << endl;
        }
    }
    return 0;
}