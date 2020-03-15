#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        LL a, b, x, y;
        cin >> a >> b >> x >> y;
        x++; y++;
        LL res = max((x - 1) * b, (y - 1) * a);
        LL res2 = max((b - y) * a, (a - x) * b);
        cout << max(res, res2) << endl;
    }
    return 0;
}