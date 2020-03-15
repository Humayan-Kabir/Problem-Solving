#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        LL a, b, c, n;
        cin >> a >> b >> c >> n;
        LL total = a + b + c + n, res = total / 3;
        if(total % 3 != 0 || max(a, max(b, c)) > res) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}