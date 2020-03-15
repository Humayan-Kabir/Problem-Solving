#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    LL t;
    cin >> t;
    while(t--) {
        LL a, b, x, y;
        cin >> x >> y >> a >> b;
        if((y - x) % (a + b) == 0) {
            cout << (y - x) / (a + b) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}