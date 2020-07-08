/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-06-11 10:37:52
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        LL n;
        cin >> n;
        n++;
        LL ans = 0;
        for(int i = 0; i < 64 && (1LL << i) <= n; i++) {
            LL block = (n + (1LL << i) - 1) / (1LL << i);
            ans += max(0LL, block - 1);
        }
        cout << ans << endl;
    }
    return 0;  
}