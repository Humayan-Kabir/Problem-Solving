/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-04-15 20:35:01
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
        int a, b, c;
        cin >> a >> b >> c;
        while(b > 0 && a >= 20) {
            a = (a / 2) + 10;
            b--;
        }
        // cout << " i " <<  a << endl;
        while(a > 0 && c > 0) {
            a -= 10;
            c--;
        }
        // cout << " i " <<  a << endl;

        if(a <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}