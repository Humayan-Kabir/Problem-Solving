#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    while(q--) {
        LL n, a, b;
        cin >> n >> a >> b;
        if(2 * a <= b) {
            cout << a * n << endl;
        }
        else {
            LL x = (n/2);
            LL ans = x * b;
            if(n & 1) ans += a;
            cout << ans << endl;
        }
    }
    return 0;
}