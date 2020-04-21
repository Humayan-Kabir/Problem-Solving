/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-04-21 20:35:01
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
LL arr[mx];
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        LL ans = 0, pre = INT_MIN;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            if((arr[i] < 0 && arr[i - 1] > 0) || (arr[i] > 0 && arr[i - 1] < 0)) {
                ans += pre;
                pre = arr[i];
                continue;
            } else {
                pre = max(pre, arr[i]);
            }
        }
        ans += pre;
        cout << ans << endl;
    }
    return 0;
}