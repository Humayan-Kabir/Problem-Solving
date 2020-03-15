#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int dp[mx], cnt[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    LL g = 0;
    for(int i = 1; i <= n; i++) {
        LL num;
        cin >> num;
        g = __gcd(g, num);
    }
    LL root = sqrt(g), ans = 0;
    for(LL i = 1; i <= root; i++) {
        if(g % i == 0) {
            LL y = g / i;
            ans++;
            if(y != i) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
