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
    while (t--){
        int a, b, ans;
        cin >> a >> b;
        if(a % b == 0) {
            ans = 0;
        } else {
            ans = b - (a % b);
        }
        cout << ans << endl;
    }
    
    return 0;
}