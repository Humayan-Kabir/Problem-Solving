#include<bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
namespace football {
    LL n, p, w, d;
    void solve() {
        scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
        for(int i = 0; i <= w && d * i <= p; i++) {
            if((p - d * i) % w == 0) {
                LL x = (p - d * i) / w, y = i;
                if(x + y <= n) {
                    cout << x << " " << y << " " << n - x - y << endl;
                    return;
                }
            } 
        }
        cout << -1 << endl;
    }
}
int main() {
    football::solve();
    return 0;
}