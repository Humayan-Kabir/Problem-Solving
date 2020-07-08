/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-13 04:22:54
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> pre(n + 1);
    for(int i = 0; i < n; i++) {
        pre[i + 1] = __gcd(pre[i], arr[i]);
    }
    vector<int> suf(n + 1);
    for(int i = n - 1; i >= 0; i--) {
        suf[i] = __gcd(suf[i + 1], arr[i]);
    }
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        int x = __gcd(pre[i], suf[i + 1]);
        ans = ans / __gcd(ans, (long long) x) * x;
    }
    cout << ans << endl;
    return 0;
}