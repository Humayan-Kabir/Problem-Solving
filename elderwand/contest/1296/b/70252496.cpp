#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        LL ans = 0;
        while(n >= 10) {
            int rem = n % 10;
            ans += (n - rem);
            n = (n / 10) + rem;
        }
        cout << ans + n << endl;
    }
    return 0;
}