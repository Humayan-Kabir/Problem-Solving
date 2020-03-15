#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
       LL n, m;
       cin >> n >> m;
       if(m == 0) {
           cout << 0 << endl;
           continue;
       }
       LL cur = (n - m), block = cur / (m + 1), rem = cur % (m + 1);
       LL left = (m + 1) - rem;
       LL blocksz = block + 1;
       LL ans = (blocksz * (blocksz + 1)) / 2LL;
       ans *= rem;
    //    cout << block << " ..>> " << ans << endl;
       ans += ((block * (block + 1)) / 2LL) * left;
    //    cout << left << " .. " << ans << endl;
       cout << ((n * (n + 1)) / 2LL) - ans << endl;
    }
    return 0;
}