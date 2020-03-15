#include<bits/stdc++.h>
using namespace std;
#define mx 300007
typedef long long int LL;
LL a[mx], b[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    LL g = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i > 1) {
            g = __gcd(g, a[i] - a[i - 1]);
        }
    }
    int f = 0;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        if(g % b[i] == 0) {
            cout << "YES" << endl;
            cout << a[1] << " " << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
