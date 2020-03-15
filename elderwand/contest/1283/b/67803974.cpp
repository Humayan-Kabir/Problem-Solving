#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if(n % k == 0) {
            cout << n << endl;
        } else {
            int rem = n % k, res = n - rem;
            cout << res + min(rem, k / 2) << endl;
        }
    }
    
    return 0;
}