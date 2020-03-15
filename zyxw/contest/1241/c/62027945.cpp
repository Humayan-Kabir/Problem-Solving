#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
LL ara[mx], vis[mx], k;
int main() {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        LL n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            vis[i] = 0;
        }
        sort(ara + 1, ara + n + 1);
        LL x, a, y, b;
        cin >> x >> a >> y >> b;
        if(y > x) {
            LL c = x, d = a;
            x = y;
            a = b;
            y = c;
            b = d;
        }
        cin >> k;
        LL ans = INT_MAX;
        LL low = 1, high = n;
        while(low <= high) {
            LL mid = (low + high) / 2;
            LL u = 0, v = 0, w = 0;
            for(LL i = 1; i <= mid; i++) {
                if(i % a == 0 && i % b == 0) {
                    u++;
                }
                else if(i % a == 0) {
                    v++;
                }
                else if(i % b == 0) {
                    w++;
                }
            }
            LL cnt = 0, sum = 0;
            for(int i = n; i >= 1; i--) {
                if(u > 0) {
                    sum += (ara[i] / 100) * (x + y);
                    u--;
                    continue;
                }
                if(v > 0) {
                    sum += (ara[i] / 100) * (x);
                    v--;
                    continue;
                }
                if(w > 0) {
                    sum += (ara[i] / 100) * (y);
                    w--;
                    continue;
                }
            }
            if(sum >= k) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(ans > n) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    } 
    return 0;
}