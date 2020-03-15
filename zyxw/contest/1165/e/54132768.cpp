#include<bits/stdc++.h>
using namespace std;
#define mx 200007
#define mod 998244353
typedef long long int LL;
LL a[mx], b[mx];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] * 1LL * i * (1LL * n - 1LL * i + 1LL);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        a[i] %= mod;
        a[i] = a[i] * b[n - i + 1];
        a[i] %= mod;
        ans += a[i];    
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
