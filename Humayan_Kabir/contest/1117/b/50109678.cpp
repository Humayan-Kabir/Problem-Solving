#include <bits/stdc++.h>
#define mx 100007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    LL n, m, k;
    cin >> n >> m >> k;
    vector <LL> vt;
    for(int i = 1; i <= n; i++) {
        LL num;
        cin >> num;
        vt.push_back(num);
    }
    sort(vt.rbegin(), vt.rend());
    LL mx1 = vt[0], mx2 = vt[1];
    if(m <= k) {
        cout << m * mx1 << endl;
        return 0;
    }
    LL d = m / (k + 1), rem = m - d;
    cout << d * mx2 + rem * mx1 << endl;
    return 0;
}