/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-31 20:49:36
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
        int zero = 0, one = 0;
        string str;
        cin >> str;
        for(char ch : str) {
            if(ch == '0') zero++;
            else one++;
        }
        int ans = min(zero, one), len = str.length(), x = 0, y = 0;
        for(int i = 0; i < len; i++) {
            if(str[i] == '0') x++;
            else y++;
            int ans1 = y + (zero - x), ans2 = x + (one - y);
            ans = min(ans, min(ans1, ans2));
        }
        cout << ans << endl;
    }
    return 0;
}