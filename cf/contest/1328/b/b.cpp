/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-03-26 20:39:02
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k, x, y;
        cin >> n >> k;
        for(int i = n - 1; i >= 1; i--) {
            int move = n - i;
            // cout << move << endl;
            if(move >= k) {  
                x = i; y = n;
                k--;
                while(k > 0) {
                    y--; k--;
                }
                break;
            } else {
                k -= move;
            }
        }
        string ans = "";
        for(int i = 1; i <= n; i++) {
            if(i == x || i == y) {
                ans += 'b';
            } else {
                ans += 'a';
            }
        }
        cout << ans << endl;
    }
    return 0;
}