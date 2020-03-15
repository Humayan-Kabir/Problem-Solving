#include<bits/stdc++.h>
#define mx 200007
#define mod 998244353
using namespace std;
typedef long long int LL;
int ara[mx];
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        sort(ara + 1, ara + n + 1);
        cout << min(min(ara[n], ara[n - 1]) - 1, n - 2) << endl;
    }
    return 0;
}